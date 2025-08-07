PORTNAME=	gorss
PORTVERSION=	0.4
DISTVERSIONPREFIX=	v
PORTREVISION=	14
CATEGORIES=	net www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple RSS/Atom reader written in Go
WWW=		https://github.com/Lallassu/gorss

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	Lallassu

.include "${.CURDIR}/Makefile.deps"

GO_BUILDFLAGS=	-ldflags "-w -X github.com/${GH_ACCOUNT}/${GH_PROJECT}/internal.Version=${PORTVERSION}"
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		${DATADIR_REL}/gorss.conf \
		${DATADIR_REL}/themes/default.theme \
		${DATADIR_REL}/themes/irssi.theme \
		${DATADIR_REL}/themes/night.theme

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/vendor/github.com/OpenPeeDeeP/xdg/xdg_bsd.go

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -a ${WRKSRC}/gorss.conf ${WRKSRC}/themes ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
