# Ports collection makefile for:	mozilla-fonts
# Date created:				10 Mar 2000
# Whom:					dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	mozilla-fonts
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	x11-fonts www
MASTER_SITES=	http://www.happygiraffe.net/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web fonts for Netscape/Mozilla

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mozilla-fonts
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mozilla-fonts
.endif
	@ ${CAT} ${DESCR}

.include <bsd.port.post.mk>
