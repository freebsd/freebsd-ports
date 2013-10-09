# Created by: Mike Krutov <neko@takino.org>
# $FreeBSD$

PORTNAME=	girara
PORTVERSION=	0.1.7
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	http://pwmt.org/projects/girara/download/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	GTK2 Interface Library for Zathura PDF Viewer

USE_GNOME=	glib20 gtk20
USES=		compiler:c11 gmake pkgconfig
USE_LDCONFIG=	yes
LIBDIR=		${PREFIX}/lib

OPTIONS_DEFINE=	NLS

OPTIONS_SUB=	yes
NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's|$${LIBDIR}/pkgconfig|${PREFIX}/libdata/pkgconfig|g'\
		${WRKSRC}/Makefile
.if ! ${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e '/-C po/d'\
		${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
