# $FreeBSD$

PORTNAME=	sql
PORTVERSION=	2.3.0.0
CATEGORIES=	textproc
MASTER_SITES=	http://github.com/NLPchina/elasticsearch-sql/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	elasticsearch2-plugin-
DISTNAME=	elasticsearch-${PORTNAME}-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	ElasticSearch SQL plugin

LICENSE=	APACHE20

RUN_DEPENDS=	elasticsearch2>=2.1.0:textproc/elasticsearch2

CONFLICTS=      elasticsearch-plugin-sql-1.*

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_SUB+=	VERSION="${PORTVERSION}"

post-patch:
	@${FIND} ${WRKSRC} -type d -empty -delete
	@${RM} ${WRKSRC}/_site/vendor/codemirror/.travis.yml

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/sql
	${INSTALL_DATA} ${WRKSRC}/*.jar ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/sql
	cd ${WRKSRC} && ${COPYTREE_SHARE} _site ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/sql
	${INSTALL_DATA} ${WRKSRC}/*.properties ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/sql

.include <bsd.port.mk>
