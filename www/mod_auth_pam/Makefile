# New ports collection makefile for:	mod_auth_pam
# Date created:				2 April 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_pam
PORTVERSION=	1.0a
CATEGORIES=	www
MASTER_SITES=	http://pam.sourceforge.net/mod_auth_pam/dist/ \
		http://www.freenix.no/~anders/

MAINTAINER=	anders@fix.no

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

APXS?=		${LOCALBASE}/sbin/apxs

do-build:
	@cd ${WRKSRC} && \
	${APXS} -c -lpam mod_auth_pam.c

do-install:
	${APXS} -i -A -n auth_pam ${WRKSRC}/mod_auth_pam.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mod_auth_pam
	${MKDIR} ${PREFIX}/share/doc/mod_auth_pam/samples
	${INSTALL_DATA} ${WRKSRC}/doc/configure.html ${PREFIX}/share/doc/mod_auth_pam/
	${INSTALL_DATA} ${WRKSRC}/doc/faq.html ${PREFIX}/share/doc/mod_auth_pam/
	${INSTALL_DATA} ${WRKSRC}/samples/dot-htaccess ${PREFIX}/share/doc/mod_auth_pam/samples/
	${INSTALL_DATA} ${WRKSRC}/samples/httpd ${PREFIX}/share/doc/mod_auth_pam/samples/
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
