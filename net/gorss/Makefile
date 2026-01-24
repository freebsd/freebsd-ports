PORTNAME=	gorss
PORTVERSION=	0.5
DISTVERSIONPREFIX=	v
CATEGORIES=	net www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple RSS/Atom reader written in Go
WWW=		https://github.com/Lallassu/gorss

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25+,modules
USE_GITHUB=	yes
GH_ACCOUNT=	Lallassu

.include "${.CURDIR}/Makefile.deps"

GO_BUILDFLAGS=	-ldflags "-w -X github.com/${GH_ACCOUNT}/${GH_PROJECT}/internal.Version=${PORTVERSION}"
GO_TARGET=	./cmd/${PORTNAME}

post-extract:
	@${LN} -sf ${FILESDIR}/modules.txt ${WRKSRC}/vendor

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/vendor/github.com/OpenPeeDeeP/xdg/xdg_bsd.go

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -a ${WRKSRC}/gorss.conf ${WRKSRC}/themes ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
