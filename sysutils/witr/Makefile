PORTNAME=	witr
PORTVERSION=	0.2.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	gaod@hychen.org
COMMENT=	Witr (why-is-this-running)
WWW=		https://github.com/pranshuparmar/witr

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25+,modules
USE_GITHUB=	yes
GH_ACCOUNT=	pranshuparmar
GH_PROJECT=	witr
GH_TUPLE=	cpuguy83:go-md2man:v2.0.7:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		spf13:cobra:v1.10.2:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.10:spf13_pflag/vendor/github.com/spf13/pflag \
		yaml:go-yaml:v3.0.4:yaml_go_yaml/vendor/go.yaml.in/yaml/v3

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-X main.version=${DISTVERSIONPREFIX}${PORTVERSION} \
		-X main.commit=${DISTVERSIONPREFIX}${PORTVERSION} \
		-X main.buildDate=2026-01-09"

PLIST_FILES=	bin/witr \
		share/man/man1/witr.1.gz

do-install:
		${INSTALL_PROGRAM} ${WRKDIR}/bin/witr ${STAGEDIR}${PREFIX}/bin/
		${INSTALL_MAN} ${WRKSRC}/docs/cli/witr.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
