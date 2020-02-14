# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	madonctl
PORTVERSION=	2.3.1
DISTVERSIONPREFIX=	v
PORTREVISION=	9
CATEGORIES=	net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI client for the Mastodon social network API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

PLIST_FILES=	bin/madonctl

GH_ACCOUNT=	McKael
GH_TAGNAME=	97f477f
USE_GITHUB=	yes

# Remove vendor/modules.txt due to inconsistent vendoring
# See https://github.com/McKael/madonctl/issues/22
post-extract:
	@${RM} ${WRKSRC}/vendor/modules.txt

.include <bsd.port.mk>
