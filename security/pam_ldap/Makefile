# New ports collection makefile for:    pam_ldap
# Date created:				26 May 2001
# Whom:	      				Joe Clarke <marcus@marcuscom.com>
#
# $FreeBSD$
#

PORTNAME=	pam_ldap
PORTVERSION=	1.6.4
CATEGORIES=	security net
MASTER_SITES=	http://www.padl.com/download/ \
		ftp://ftp.padl.com/pub/
DISTNAME=	pam_ldap-${PORTVERSION:S/.//g}

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	A pam module for authenticating with LDAP

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//g}
CONFIGURE_ARGS=	--with-ldap-lib=openldap \
		--with-ldap-dir=${LOCALBASE} \
		--with-ldap-conf-file=${PREFIX}/etc/ldap.conf \
		--with-ldap-secret-file=${PREFIX}/etc/ldap.secret
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.if !defined(WITHOUT_LDAP_V3)
LIB_DEPENDS=	ldap.2:${PORTSDIR}/net/openldap21-client
.else
LIB_DEPENDS=	ldap.1:${PORTSDIR}/net/openldap12
.endif

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

.include <bsd.port.mk>
