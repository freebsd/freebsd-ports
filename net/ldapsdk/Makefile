# New ports collection makefile for:	perldap
# Date created:	17 May 1999
# Whom:		paul@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	ldapsdk
PORTVERSION=	1998.12.31
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	directory/c-sdk/ldap

DISTNAME=	ldapsdk_12311998

MAINTAINER=	paul@FreeBSD.org
COMMENT=	Mozilla LDAP sdk

WRKSRC=			${WRKDIR}/mozilla
MAKEFILE=	${WRKSRC}/directory/ldapsdk.mk
USE_GMAKE=	yes
USE_PERL5=	yes

MAKE_ENV+=	MOZILLA_CLIENT=1 NO_MDUPDATE=1 MOZ_LDAP_SDK=1
ALL_TARGET=		build

OBJDIR=	${WRKSRC}/dist/${OPSYS}${OSREL}_DBG.OBJ
INSTALL_DIR= ${PREFIX}/mozilla/directory

do-install:
	${MKDIR} ${INSTALL_DIR}/etc
	${MKDIR} ${INSTALL_DIR}/include
	${MKDIR} ${INSTALL_DIR}/lib
	${INSTALL_DATA} ${OBJDIR}/bin/liblber.so.1.0 \
						${PREFIX}/lib/libmozlber.so.1
	-(cd ${PREFIX}/lib; ${LN} -s libmozlber.so.1 libmozlber.so)
	${INSTALL_DATA} ${OBJDIR}/bin/libldap.so.1.0 \
						${PREFIX}/lib/libmozldap.so.1
	-(cd ${PREFIX}/lib; ${LN} -s libmozldap.so.1 libmozldap.so)
	${INSTALL_DATA} ${OBJDIR}/lib/liblber.a ${PREFIX}/lib/libmozlber.a
	${INSTALL_DATA} ${OBJDIR}/lib/libldap.a ${PREFIX}/lib/libmozldap.a
	cd ${OBJDIR}/etc && ${TAR} -chf - * | \
		${TAR} -xf - -C ${INSTALL_DIR}/etc
	cd ${OBJDIR}/include && ${TAR} -chf - * | \
		${TAR} -xf - -C ${INSTALL_DIR}/include
	cd ${INSTALL_DIR}/include \
		&& [ -f lber.h ] \
		&& ( cat lber.h | sed -e 's/ldap\.h/mozldap\.h/' > mozlber.h ) \
		&& rm lber.h \
		&& [ -f ldap.h ] \
		&& ( cat ldap.h | sed -e 's/lber\.h/mozlber\.h/' > mozldap.h ) \
		&& rm ldap.h
	${LN} -sf ${INSTALL_DIR}/include/mozlber.h ${PREFIX}/include
	${LN} -sf ${INSTALL_DIR}/include/mozldap.h ${PREFIX}/include

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	@echo 
	@echo 'PLEASE NOTE (2000/8/23):'
	@echo '     The mozilla lber and ldap libraries now are installed'
	@echo '     with the names mozlber and mozldap.'
	@echo
	@echo '     This has been done to resolve a library naming conflict with '
	@echo '     the openldap port.  Also, these libraries and related'
	@echo '     header files are now installed by default in the standard'
	@echo '     directories /usr/local/lib and /usr/local/include.'
	@echo
	@echo '     The complete set of mozilla ldapsdk header files'
	@echo '     has been installed in /usr/local/mozilla/directory/include,'
	@echo '     should you require one of the more esoteric ones.'
	@echo
	@echo '     Also, please note that the PerLDAP port (../perldap) has'
	@echo '     been updated to link appropriately to these new library names.'
	@echo

.include <bsd.port.mk>
