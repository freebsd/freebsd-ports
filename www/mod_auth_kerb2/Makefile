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
COMMENT=	An Apache module for authenticating users with Kerberos v5

#
# This module allows users to send their Kerberos password in
# plain text; it should only be used over an encrypted connection
# (i.e., HTTP over SSL/TLS).  Thus, we require as a dependency
# a version of Apache which can do this.
#
LIB_DEPENDS=	krb5.3:${PORTSDIR}/security/krb5

USE_APACHE=	yes
WRKSRC=		${WRKDIR}/src/modules/kerberos

KRB5_HOME?=	${LOCALBASE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

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

.include <bsd.port.post.mk>
