PORTNAME=	tgpt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.1
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	AI Chatbots in terminal without needing API keys
WWW=		https://github.com/aandrew-me/tgpt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/aandrew-me/tgpt/v2

post-patch:
	${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor

PLIST_FILES=	bin/tgpt

.include <bsd.port.mk>
