# New ports collection makefile for:    pam_ldap
# Date created:				26 May 2001
# Whom:	      				Joe Clarke <marcus@marcuscom.com>
#
# $FreeBSD$
#

PORTNAME=	pam_ldap
PORTVERSION=	1.5.6
CATEGORIES=	security net
MASTER_SITES=	http://www.padl.com/download/ \
		ftp://ftp.padl.com/pub/
DISTNAME=	pam_ldap-${PORTVERSION:S/.//g}

MAINTAINER=	marcus@FreeBSD.org

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_LDAP_V3)
LIB_DEPENDS=	ldap.2:${PORTSDIR}/net/openldap2 \
		lber.2:${PORTSDIR}/net/openldap2
.else
LIB_DEPENDS=	ldap.1:${PORTSDIR}/net/openldap \
		lber.1:${PORTSDIR}/net/openldap
.endif

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//g}
CONFIGURE_ARGS=	--with-ldap-lib=openldap \
		--with-ldap-dir=${LOCALBASE} \
		--with-ldap-conf-file=${PREFIX}/etc/ldap.conf \
		--with-ldap-secret-file=${PREFIX}/etc/ldap.secret
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

post-extract:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f

post-install:
	@${ECHO} "================================================================================"
	@${ECHO} "Copy/move/symlink ${PREFIX}/etc/ldap.conf.dist to"
	@${ECHO} "${PREFIX}/etc/ldap.conf to be able to use it."
	@${ECHO} "Add lines like the following to /etc/pam.conf"
	@${ECHO} "to get things going:"
	@${ECHO} ""
	@${ECHO} "login    auth    sufficient    ${PREFIX}/lib/pam_ldap.so"
	@${ECHO} "================================================================================"

.include <bsd.port.post.mk>
