PORTNAME=	csvtk
DISTVERSIONPREFIX=	v
DISTVERSION=	0.24.0
PORTREVISION=	4
CATEGORIES=	science

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Cross-platform and ultrafast toolkit for CSV/TSV processing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/shenwei356/csvtk
GO_TARGET=	./${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
