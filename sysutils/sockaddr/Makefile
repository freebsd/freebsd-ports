# $FreeBSD$

PORTNAME=	sockaddr
DISTVERSION=	g20180320
CATEGORIES=	sysutils

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Command line utility for querying IP information

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_SUBDIR=	src/github.com/hashicorp/go-sockaddr
GH_ACCOUNT=	hashicorp
GH_PROJECT=	go-sockaddr
GH_TAGNAME=	7165ee1

PLIST_FILES=	bin/sockaddr

post-extract:
	@${CP} -rp ${WRKSRC}/cmd/${PORTNAME}/vendor/* ${WRKSRC}/src/

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/cmd/${PORTNAME}/ && \
	${SETENV} ${MAKE_ENV} CGO_ENABLED=0 GOPATH=${WRKSRC} \
	${LOCALBASE}/bin/go build -ldflags "-X main.version=${DISTVERSIONPREFIX}${PORTVERSION} -w -s" \
		-o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/hashicorp/go-sockaddr/cmd/${PORTNAME}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
