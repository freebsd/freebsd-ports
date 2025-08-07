PORTNAME=	termshark
PORTVERSION=	2.4.0
DISTVERSIONPREFIX=v
PORTREVISION=	26
CATEGORIES=	net

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Terminal UI for tshark, inspired by Wireshark
WWW=		https://termshark.io/

LICENSE=	MIT

USES=		go:modules

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=

X11_RUN_DEPENDS_OFF=	wireshark-nox11>0:net/wireshark@nox11
X11_RUN_DEPENDS=	wireshark>0:net/wireshark

GO_MODULE=	github.com/gcla/termshark/v2
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	${RM} ${WRKSRC}/pkg/system/dumpcapext_arm64.go

.include <bsd.port.mk>
