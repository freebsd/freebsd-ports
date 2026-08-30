PORTNAME=	tgpt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.14.0
CATEGORIES=	www

MAINTAINER=	nxjoseph@FreeBSD.org
COMMENT=	AI Chatbots in terminal without needing API keys
WWW=		https://github.com/aandrew-me/tgpt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/aandrew-me/tgpt/v2
# Skip failing Windows tests
GO_TESTFLAGS=	-skip="TestDetectPackageManager/Scoop_on_Windows|TestDetectPackageManager/Chocolatey_on_Windows"

post-patch:
	${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor

PLIST_FILES=	bin/tgpt

.include <bsd.port.mk>
