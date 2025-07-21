PORTNAME=	vacuum
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.6
CATEGORIES=	textproc
PKGNAMESUFFIX=	-lint-tool

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenAPI/Swagger linter and quality analysis tool
WWW=		https://quobix.com/vacuum/ \
		https://github.com/daveshanley/vacuum

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

GO_MODULE=	github.com/daveshanley/vacuum

PLIST_FILES=	bin/${PORTNAME}

do-test:
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} lint ${WRKSRC}/model/test_files/petstorev3.json

.include <bsd.port.mk>
