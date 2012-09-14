# New ports collection makefile for:	zathura
# Date created:				23 April 2012
# Whom:					Mike Krutov <neko@takino.org>
#
# $FreeBSD$
#

PORTNAME=	girara
PORTVERSION=	0.1.3
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	http://pwmt.org/projects/girara/download/

MAINTAINER=	neko@takino.org
COMMENT=	GTK2 Interface Library for Zathura PDF Viewer

USE_GNOME=	glib20 gtk20
USE_GMAKE=	yes
USE_LDCONFIG=	yes
FETCH_ARGS=	-Fpr

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

LIBDIR=		${PREFIX}/lib

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's|$${LIBDIR}/pkgconfig|${PREFIX}/libdata/pkgconfig|g'\
		${WRKSRC}/Makefile
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e '/-C po/d'\
		${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
