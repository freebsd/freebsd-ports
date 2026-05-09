PORTNAME=	camsnap
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI to access RTSP/ONVIF devices (e.g. IP cameras)
WWW=		https://github.com/steipete/camsnap/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24+,modules

GO_MODULE=	github.com/steipete/camsnap
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
