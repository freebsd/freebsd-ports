# New ports collection makefile for:	mod_auth_kerb
# Date created:				19 October 2001
# Whom:					wollman
#
# $FreeBSD$
#

# Shamelessly stolen from will's mod_auth_any port.

PORTNAME=	mod_auth_kerb
PORTVERSION=	4.11
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=modauthkerb

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
		${APXS} -I${KRB5_HOME}/include \
		-DKRB5 -DKRB5_VERIFY_TICKET -DKRB5_SAVE_CREDENTIALS \
		-DKRB5_DEFAULT_KEYTAB=\"\\\"FILE:${LOCALBASE}/etc/apache/keytab\\\"\" \
		-Dkerb_auth_module=auth_kerb_module \
		-c ${PORTNAME}.c \
		-L${KRB5_HOME}/lib -Wl,-rpath -Wl,${KRB5_HOME}/lib \
		-lkrb5 -lk5crypto -lcom_err

do-install:
	${APXS} -i -A -n ${PORTNAME:S/mod_//g} ${WRKSRC}/${PORTNAME}.so

.include <bsd.port.mk>
