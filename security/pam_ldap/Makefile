# New ports collection makefile for:    pam_ldap
# Date created:				26 May 2001
# Whom:	      				Joe Clarke <marcus@marcuscom.com>
#
# $FreeBSD$
#

PORTNAME=	pam_ldap
PORTVERSION=	1.3.7
CATEGORIES=	security net
MASTER_SITES=	http://www.padl.com/download/ \
		ftp://ftp.padl.com/pub/
DISTNAME=	pam_ldap-${PORTVERSION:S/.//g}

MAINTAINER=	marcus@marcuscom.com

.if defined(WITH_LDAP_V3)
LIB_DEPENDS=	ldap.2:${PORTSDIR}/net/openldap2 \
		lber.2:${PORTSDIR}/net/openldap2
.else
LIB_DEPENDS=	ldap.1:${PORTSDIR}/net/openldap \
		lber.1:${PORTSDIR}/net/openldap
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ldap-lib=openldap \
		--with-ldap-dir=${LOCALBASE} \
		--with-ldap-conf-file=${PREFIX}/etc/ldap.conf
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//g}

post-extract:
	@find ${WRKSRC} -type f | xargs touch -f

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
