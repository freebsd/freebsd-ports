# Created by: Miguel Mendez <flynn@energyhq.homeip.net>
# $FreeBSD$

PORTNAME=	thefish
PORTVERSION=	0.6.7
CATEGORIES=	sysutils
MASTER_SITES=	https://BSDforge.com/projects/source/sysutils/thefish/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Gtk+/ncurses rc.conf editor/management tool

LICENSE=	BSD2CLAUSE

USES=		gnome pkgconfig tar:xz

OPTIONS_SINGLE=		X11
OPTIONS_SINGLE_X11=	GTK2
OPTIONS_DEFAULT=	GTK2

.include <bsd.port.options.mk>

#.if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20
MAKE_ENV+=	WITH_GTK=yes
#.endif

PLIST_FILES=	bin/thefish man/man1/thefish.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/thefish ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/thefish.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
