# New ports collection makefile for:	mod_auth_external
# Date created:				14 May 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_external
PORTVERSION=	2.1.14
CATEGORIES=	www
MASTER_SITES=	http://www.wwnet.net/~janc/software/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	anders@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

APXS?=		${LOCALBASE}/sbin/apxs

DOCDIR=		${PREFIX}/share/doc/${PORTNAME}
DOCS=		AUTHENTICATORS CHANGES INSTALL README TODO

do-build:
	@cd ${WRKSRC} && ${APXS} -c mod_auth_external.c

do-install:
	${APXS} -i -A -n auth_external ${WRKSRC}/mod_auth_external.so
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCDIR}/examples
	cd ${WRKSRC} && ${TAR} -chf - pwauth radius sybase test \
		| ${TAR} -xf - -C ${DOCDIR}/examples
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}/
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
