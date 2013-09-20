# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	libkmfl
PORTVERSION=	0.9.9
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/kmfl/kmfl/${PORTVERSION} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	An engine to interpret compiled KMFL keyboard tables

LIB_DEPENDS=	kmflcomp.0:${PORTSDIR}/textproc/kmflcomp

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCSDIR=	${PREFIX}/share/doc/kmfl/${PORTNAME}
PORTDOCS=	AUTHORS COPYING ChangeLog

PLIST_FILES=	include/kmfl/libkmfl.h \
		lib/libkmfl.a \
		lib/libkmfl.la \
		lib/libkmfl.so \
		lib/libkmfl.so.0
PLIST_DIRSTRY=	include/kmfl

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} \
		's|^install-data-am: install-libkmfldocDATA|install-data-am:|' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
