# New ports collection makefile for:    libkmfl
# Date created:		10 October 2007
# Whom:			Nikola Lecic <nikola.lecic@anthesphoria.net>
#
# $FreeBSD$
#

PORTNAME=	libkmfl
PORTVERSION=	0.9.8
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/kmfl/kmfl/${PORTVERSION} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	An engine to interpret compiled KMFL keyboard tables

LIB_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp

USE_LDCONFIG=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCSDIR=	${PREFIX}/share/doc/kmfl/${PORTNAME}
PORTDOCS=	AUTHORS COPYING ChangeLog

PLIST_FILES=	include/kmfl/libkmfl.h \
		lib/libkmfl.a \
		lib/libkmfl.la \
		lib/libkmfl.so \
		lib/libkmfl.so.0

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
