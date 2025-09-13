PORTNAME=	lazyssh
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
CATEGORIES=	sysutils

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Terminal-based interactive SSH Manager to manage your servers
WWW=		https://github.com/Adembc/lazyssh \
		https://pkg.go.dev/github.com/Adembc/lazyssh

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/Adembc/${PORTNAME}
GO_TARGET=	./cmd:${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X main.version=${DISTVERSIONFULL} -X main.gitCommit=b7fb586"

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFAULT=		XCLIP
OPTIONS_MULTI=			CLIPBOARD
OPTIONS_MULTI_CLIPBOARD=	XCLIP XSEL

CLIPBOARD_DESC=		Select which clipboard manager to install
XCLIP_DESC=		Install x11/xclip for clipboard operations
XSEL_DESC=		Install x11/xsel-conrad for clipboard operations
XCLIP_RUN_DEPENDS=	xclip:x11/xclip
XSEL_RUN_DEPENDS=	xsel:x11/xsel-conrad

.include <bsd.port.mk>
