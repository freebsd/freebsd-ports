# New ports collection makefile for:	perldap
# Version required:	1.1b
# Date created:	17 May 1999
# Whom:		paul@freebsd.org
#
# $Id: Makefile,v 1.1.1.1 1999/05/25 22:44:25 paul Exp $
#

DISTNAME=	ldapsdk_12311998
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.mozilla.org/pub/directory/c-sdk/ldap/

MAINTAINER=	paul@FreeBSD.ORG

WRKSRC=			${WRKDIR}/mozilla
MAKEFILE=	${WRKSRC}/directory/ldapsdk.mk
USE_GMAKE=	yes

MAKE_ENV+=	MOZILLA_CLIENT=1 NO_MDUPDATE=1 MOZ_LDAP_SDK=1
ALL_TARGET=		build

OBJDIR=	${WRKSRC}/dist/${OPSYS}${OSREL}_DBG.OBJ
INSTALL_DIR= ${PREFIX}/mozilla/directory

do-install:
	mkdir	-p ${INSTALL_DIR}/etc
	mkdir	-p ${INSTALL_DIR}/include
	mkdir	-p ${INSTALL_DIR}/lib
	${INSTALL_DATA} ${OBJDIR}/bin/liblber.so.1.0 \
						${INSTALL_DIR}/lib/liblber.so.1
	-(cd ${INSTALL_DIR}/lib; ln -s liblber.so.1 liblber.so)
	${INSTALL_DATA} ${OBJDIR}/bin/libldap.so.1.0 \
						${INSTALL_DIR}/lib/libldap.so.1
	-(cd ${INSTALL_DIR}/lib; ln -s libldap.so.1 libldap.so)
	cd ${OBJDIR}/etc && ${TAR} -chf - * | \
		${TAR} -xf - -C ${INSTALL_DIR}/etc
	cd ${OBJDIR}/include && ${TAR} -chf - * | \
		${TAR} -xf - -C ${INSTALL_DIR}/include
	cd ${OBJDIR}/lib && ${TAR} -chf - * | \
		${TAR} -xf - -C ${INSTALL_DIR}/lib

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/mozilla/directory/lib

.include <bsd.port.mk>
