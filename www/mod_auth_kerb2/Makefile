# New ports collection makefile for:	mod_auth_kerb
# Date created:				19 October 2001
# Whom:					wollman
#
# $FreeBSD$
#

# Shamelessly stolen from will's mod_auth_any port.

PORTNAME=	mod_auth_kerb
PORTVERSION=	4.10
CATEGORIES=	www
MASTER_SITES=	http://stonecold.unity.ncsu.edu/software/mod_auth_kerb/downloads/

MAINTAINER=	wollman@FreeBSD.org

#
# This module allows users to send their Kerberos password in
# plain text; it should only be used over an encrypted connection
# (i.e., HTTP over SSL/TLS).  Thus, we require as a dependency
# a version of Apache which can do this.
#
BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13-modssl
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13-modssl
LIB_DEPENDS=	krb5.3:${PORTSDIR}/security/krb5

WRKSRC=		${WRKDIR}/src/modules/kerberos

APXS?=		${LOCALBASE}/sbin/apxs
KRB5_HOME?=	${LOCALBASE}

do-build:
	cd ${WRKSRC} && \
		${APXS} -I${KRB5_HOME}/include -L${KRB5_HOME}/lib \
		-DKRB5 -DKRB5_VERIFY_TICKET -DKRB5_SAVE_CREDENTIALS \
		-DKRB5_DEFAULT_KEYTAB=\"\\\"file:${LOCALBASE}/etc/apache/keytab\\\"\" \
		-c ${PORTNAME}.c

do-install:
	${APXS} -i -A -n ${PORTNAME:S/mod_//g} ${WRKSRC}/${PORTNAME}.so

.include <bsd.port.mk>
