PORTNAME=	walk
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.0
PORTREVISION=	4
CATEGORIES=	sysutils

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Terminal file manager
WWW=		https://github.com/antonmedv/${PORTNAME}

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=			go:modules
GO_MODULE=		github.com/antonmedv/${PORTNAME}
CONFLICTS_INSTALL=	4ti2

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_RADIO=			CLIPBOARD
OPTIONS_RADIO_CLIPBOARD=	WL_COPY XCLIP XSEL

WL_COPY_DESC=	Use wl-copy
XCLIP_DESC=	Use xclip
XSEL_DESC=	Use xsel-conrad

WL_COPY_RUN_DEPENDS=	wl-clipboard>0:x11/wl-clipboard
XCLIP_RUN_DEPENDS=	xclip>0:x11/xclip
XSEL_RUN_DEPENDS=	xsel-conrad>0:x11/xsel-conrad

.include <bsd.port.mk>
