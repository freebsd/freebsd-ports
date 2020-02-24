# $FreeBSD$

PORTNAME=	grok_exporter
PORTVERSION=	0.2.3
DISTVERSIONPREFIX=v
PORTREVISION=	3
CATEGORIES=	net-mgmt

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Export Prometheus metrics from arbitrary unstructured log data

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	fstab logstash-plugins:plugins
GH_PROJECT=	logstash-patterns-core:plugins
GH_TAGNAME=	6d25c13:plugins
USERS=		prometheus
GROUPS=		prometheus

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
USE_RC_SUBR=	grok_exporter
SUB_FILES=	config.yml

post-patch:
	${LN} -sf ${WRKSRC}/tailer/fileTailer_darwin.go ${WRKSRC}/tailer/fileTailer_freebsd.go

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/config.yml ${STAGEDIR}${ETCDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} example ${STAGEDIR}${DATADIR})
	@(cd ${WRKSRC_plugins} && ${COPYTREE_SHARE} patterns ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
