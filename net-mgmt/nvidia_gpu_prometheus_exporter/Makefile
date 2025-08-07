PORTNAME=	nvidia_gpu_prometheus_exporter
DISTVERSION=	g20181028
PORTREVISION=	29
CATEGORIES=	net-mgmt

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	NVIDIA GPU Prometheus exporter
WWW=		https://github.com/mindprince/nvidia_gpu_prometheus_exporter

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	mindprince
GH_TAGNAME=	0d52cd2

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
