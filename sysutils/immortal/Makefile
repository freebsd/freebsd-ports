PORTNAME=	immortal
PORTVERSION=	0.24.4
PORTREVISION=	23
CATEGORIES=	sysutils

MAINTAINER=	nbari@tequila.io
COMMENT=	Unix cross-platform (OS agnostic) supervisor
WWW=		https://immortal.run

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	immortaldir
USE_GITHUB=	yes
GH_TUPLE=	go-check:check:20d25e280405:go_check_check/vendor/gopkg.in/check.v1 \
		go-yaml:yaml:v2.1.0:go_yaml_yaml/vendor/github.com/go-yaml/yaml \
		go-yaml:yaml:v2.2.8:go_yaml_yaml_1/vendor/gopkg.in/yaml.v2 \
		immortal:logrotate:5a04431dbafb:immortal_logrotate/vendor/github.com/immortal/logrotate \
		immortal:multiwriter:2e0dd11a3549:immortal_multiwriter/vendor/github.com/immortal/multiwriter \
		immortal:natcasesort:53ad4be8bc1a:immortal_natcasesort/vendor/github.com/immortal/natcasesort \
		immortal:xtime:fb1aca1146ea:immortal_xtime/vendor/github.com/immortal/xtime \
		nbari:violetear:ce83b52538c9:nbari_violetear/vendor/github.com/nbari/violetear
GH_SUBDIR=	src/github.com/${PORTNAME}/${PORTNAME}

GO_BUILDFLAGS=	-ldflags "-s -w -X main.version=${PORTVERSION}"
GO_TARGET=	./cmd/immortal \
		./cmd/immortalctl \
		./cmd/immortaldir

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/github.com/immortal/immortal/man/*.8 ${STAGEDIR}${PREFIX}/share/man/man8/
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/www.yml ${STAGEDIR}${EXAMPLESDIR}/www.yml.sample

.include <bsd.port.mk>
