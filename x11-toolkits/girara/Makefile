# Created by: Mike Krutov <neko@takino.org>
# $FreeBSD$

PORTNAME=	girara
PORTVERSION=	0.2.6
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	http://pwmt.org/projects/girara/download/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	GTK3 Interface Library for Zathura PDF Viewer

USE_GNOME=	glib20 gtk30
USES=		compiler:c11 gmake pkgconfig
USE_LDCONFIG=	yes
LIBDIR=		${PREFIX}/lib
MAKE_ENV+=	SFLAGS=${STRIP}

OPTIONS_DEFINE=	NLS

OPTIONS_SUB=	yes
NLS_USES=	gettext

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's|$${LIBDIR}/pkgconfig|${PREFIX}/libdata/pkgconfig|g'\
		${WRKSRC}/Makefile

post-patch-NLS-off: .SILENT
	${REINPLACE_CMD} -e '/-C po/d'\
		${WRKSRC}/Makefile

.include <bsd.port.mk>
