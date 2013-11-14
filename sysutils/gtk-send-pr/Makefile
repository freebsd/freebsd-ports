# Created by: Miguel Mendez <flynn@energyhq.es.eu.org>
# $FreeBSD$

PORTNAME=	gtk-send-pr
PORTVERSION=	0.4.9
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 send-pr tool

LIB_DEPENDS=	libesmtp.so:${PORTSDIR}/mail/libesmtp

USES=		pkgconfig
USE_GNOME=	gtk20

PLIST_FILES=	bin/gtk-send-pr man/man1/${PORTNAME}.1.gz share/pixmaps/ladybird64.xpm
DESKTOP_ENTRIES="Send Problem Report" \
		"Send a FreeBSD PR" \
		"${PREFIX}/share/pixmaps/ladybird64.xpm" \
		"gtk-send-pr" \
		"System;" \
		true

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gtk-send-pr ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/common/gtk-send-pr.1 ${STAGEDIR}${PREFIX}/man/man1
	@${INSTALL_DATA} ${WRKSRC}/icon/ladybird64.xpm ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
