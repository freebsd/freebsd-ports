# Created by: Akinori MUSHA aka knu <knu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	peco
PORTVERSION=	0.2.0.20140714
CATEGORIES=	textproc

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Simplistic interactive filtering tool

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/github.com/jessevdk/go-flags.a:${PORTSDIR}/devel/go-flags \
		${LOCALBASE}/${GO_LIBDIR}/github.com/mattn/go-runewidth.a:${PORTSDIR}/devel/go-runewidth \
		${LOCALBASE}/${GO_LIBDIR}/github.com/nsf/termbox-go.a:${PORTSDIR}/devel/go-termbox

USE_GITHUB=	yes
GH_ACCOUNT=	peco
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	6135199

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${PORTNAME}-${GH_COMMIT}/cmd/peco
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}/cmd/peco
PLIST_FILES=	bin/peco

post-extract:
	@${MKDIR} ${GO_WRKSRC:H:H:H}
	@${LN} -sf ${WRKSRC:H:H} ${GO_WRKSRC:H:H}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
