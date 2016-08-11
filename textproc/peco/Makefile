# Created by: Akinori MUSHA aka knu <knu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	peco
PORTVERSION=	0.3.5
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Simplistic interactive filtering tool

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/github.com/jessevdk/go-flags.a:devel/go-flags \
		${LOCALBASE}/${GO_LIBDIR}/github.com/mattn/go-runewidth.a:devel/go-runewidth \
		${LOCALBASE}/${GO_LIBDIR}/github.com/nsf/termbox-go.a:devel/go-termbox \
		${LOCALBASE}/${GO_LIBDIR}/github.com/google/btree.a:devel/go-btree

USES=		go
USE_GITHUB=	yes

WRKSRC_SUBDIR=	cmd/peco
GO_PKGNAME=	github.com/${PORTNAME}/${PORTNAME}/cmd/peco
PLIST_FILES=	bin/peco

post-extract:
	@${MKDIR} ${GO_WRKSRC:H:H:H}
	@${LN} -sf ${WRKSRC:H:H} ${GO_WRKSRC:H:H}

.include <bsd.port.mk>
