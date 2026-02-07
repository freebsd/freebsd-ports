PORTNAME=	yarn
DISTVERSIONPREFIX=	v
PORTVERSION=	1.22.19
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://yarnpkg.com/downloads/${PORTVERSION}/
PKGNAMESUFFIX=	${NODEJS_SUFFIX}

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Package manager for node, alternative to npm
WWW=		https://classic.yarnpkg.com/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES?=		nodejs:24,run
USES+=		cpe
CPE_VENDOR=	${PORTNAME}pkg

CONFLICTS_INSTALL=	yarn-node[0-9][0-9]

OPTIONS_DEFINE=	HADOOPCOMPAT
HADOOPCOMPAT_DESC=	hadoop2 compatibility, the yarn script is excluded

OPTIONS_SUB=	yes

HADOOPCOMPAT_CONFLICTS_INSTALL_OFF=	hadoop2*

NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	@${RM} ${WRKSRC}/bin/*.cmd
	@${REINPLACE_CMD} -i '' \
		-e 's|"installationMethod": "tar"|"installationMethod": "pkg"|g' \
		${WRKSRC}/package.json
	@${REINPLACE_CMD} -i '' -e 's%Linux)%Linux|FreeBSD)%g' \
		${WRKSRC}/bin/yarn

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/yarn
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/node_modules/yarn)
	${RLN} ${STAGEDIR}${PREFIX}/lib/node_modules/yarn/bin/yarn.js \
		${STAGEDIR}${PREFIX}/bin/yarn.js
	${RLN} ${STAGEDIR}${PREFIX}/lib/node_modules/yarn/bin/yarnpkg \
		${STAGEDIR}${PREFIX}/bin/yarnpkg

do-install-HADOOPCOMPAT-off:
	${RLN} ${STAGEDIR}${PREFIX}/lib/node_modules/yarn/bin/yarn \
		${STAGEDIR}${PREFIX}/bin/yarn

.include <bsd.port.mk>
