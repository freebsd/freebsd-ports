PORTNAME=	dendrite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.1
PORTREVISION=	4
CATEGORIES=	net-im

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Matrix protocol homeserver
WWW=		https://github.com/element-hq/dendrite

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:1.23,modules
CPE_VENDOR=	matrix
PLIST_SUB=	PORTNAME=${PORTNAME}
USE_RC_SUBR=	${PORTNAME}
USERS=		${PORTNAME}
GROUPS=		${USERS}

DENDRITE_BINS=	create-account dendrite-demo-pinecone			\
		dendrite-demo-yggdrasil dendrite			\
		dendrite-upgrade-tests furl generate-config 		\
		generate-keys resolve-state

.for f in ${DENDRITE_BINS}
GO_TARGET+=	./cmd/$f:${PREFIX}/dendrite/bin/$f
.endfor

GO_MODULE=	github.com/element-hq/dendrite

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dendrite-sample.yaml ${STAGEDIR}${ETCDIR}/${PORTNAME}.yaml.sample
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
