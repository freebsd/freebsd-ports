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

GO_BUILDFLAGS=	-ldflags "-X main.version=${DISTVERSIONPREFIX}${PORTVERSION} -w -s"
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/sockaddr

post-patch:
	@${LN} -s ${WRKSRC}/cmd/${PORTNAME}/vendor ${WRKSRC}

.include <bsd.port.mk>
