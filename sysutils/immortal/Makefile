# $FreeBSD$

PORTNAME=	immortal
PORTVERSION=	0.24.1
CATEGORIES=	sysutils

MAINTAINER=	nbari@tequila.io
COMMENT=	Unix cross-platform (OS agnostic) supervisor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_RC_SUBR=	immortaldir
USE_GITHUB=	yes
GH_TUPLE=	immortal:logrotate:6f52ae7:logrotate/vendor/github.com/immortal/logrotate \
		immortal:multiwriter:2e0dd11:multiwriter/vendor/github.com/immortal/multiwriter \
		immortal:natcasesort:162328b:natcasesort/vendor/github.com/immortal/natcasesort \
		immortal:xtime:fb1aca1:xtime/vendor/github.com/immortal/xtime \
		nbari:violetear:5c7cdfe:nbari/vendor/github.com/nbari/violetear \
		go-yaml:yaml:51d6538:yaml/vendor/github.com/go-yaml/yaml
GH_SUBDIR=	src/github.com/${PORTNAME}/${PORTNAME}

GO_BUILDFLAGS=	-ldflags "-s -w -X main.version=${PORTVERSION}"
GO_TARGET=	./cmd/immortal \
		./cmd/immortalctl \
		./cmd/immortaldir

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/github.com/immortal/immortal/man/*.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/www.yml ${STAGEDIR}${EXAMPLESDIR}/www.yml.sample

.include <bsd.port.mk>
