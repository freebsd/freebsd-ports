# $FreeBSD$

PORTNAME=	sql
PORTVERSION=	1.4.4
CATEGORIES=	textproc
MASTER_SITES=	http://github.com/NLPchina/elasticsearch-sql/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	elasticsearch-plugin-
DISTNAME=	elasticsearch-${PORTNAME}-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	ElasticSearch SQL plugin

LICENSE=	APACHE20

RUN_DEPENDS=	elasticsearch>=1.5.0:${PORTSDIR}/textproc/elasticsearch

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_SUB+=	VERSION="${PORTVERSION}"

post-patch:
	@${RM} ${WRKSRC}/_site/vendor/codemirror/.travis.yml

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/sql
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/sql/_site
	${INSTALL_DATA} ${WRKSRC}/*.jar ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/sql
	cd ${WRKSRC} && ${COPYTREE_SHARE} _site ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/sql

.include <bsd.port.mk>
