PORTNAME=	mongodb_exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.45.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Prometheus exporter for MongoDB
WWW=		https://github.com/percona/mongodb_exporter

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules
USE_RC_SUBR=	mongodb_exporter

GO_MODULE=	github.com/percona/mongodb_exporter

GO_BUILDFLAGS=	-ldflags='\
		-s -w \
		-X main.version=${DISTVERSIONPREFIX}${DISTVERSION} \
		-X main.GitCommit=${GITID} \
		-X main.GoVersion=${GO_DEFAULT_VERSION}'

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
