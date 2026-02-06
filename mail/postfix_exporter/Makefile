PORTNAME=	postfix_exporter
DISTVERSIONPREFIX=v
DISTVERSION=	0.21.2
CATEGORIES=	mail
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	zeha@ccsej.de
COMMENT=	Prometheus exporter for postfix metrics
WWW=		https://github.com/Hsn723/postfix_exporter

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules
USE_RC_SUBR=	postfix_exporter

GO_MODULE=	github.com/Hsn723/postfix_exporter

GO_BUILDFLAGS=	-tags nosystemd,nodocker

PLIST_FILES=	bin/postfix_exporter

.include <bsd.port.mk>
