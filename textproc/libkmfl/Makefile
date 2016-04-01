# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	libkmfl
PORTVERSION=	0.9.9
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/kmfl/kmfl/${PORTVERSION} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Engine to interpret compiled KMFL keyboard tables

LIB_DEPENDS=	libkmflcomp.so:textproc/kmflcomp

USE_LDCONFIG=	yes
USES=	libtool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS
DOCSDIR=	${PREFIX}/share/doc/kmfl/${PORTNAME}
PORTDOCS=	AUTHORS COPYING ChangeLog

PLIST_FILES=	include/kmfl/libkmfl.h \
		lib/libkmfl.a \
		lib/libkmfl.so \
		lib/libkmfl.so.0.0.0 \
		lib/libkmfl.so.0

post-patch:
	@${REINPLACE_CMD} \
		's|^install-data-am: install-libkmfldocDATA|install-data-am:|' \
		${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
. endfor

.include <bsd.port.mk>
