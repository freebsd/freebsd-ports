# Created by: Vyacheslav Anikin <anikinsl@gmail.com>
# $FreeBSD$

PORTNAME=	pidgin-osd
PORTVERSION=	0.1.0
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	https://babelize.org/download/pidgin-osd/

MAINTAINER=	anikinsl@gmail.com
COMMENT=	A pidgin plugin for displaying new messages on screen

BUILD_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin \
		xosd>=2.2.12:${PORTSDIR}/misc/xosd
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin \
		xosd>=2.2.12:${PORTSDIR}/misc/xosd

USES=		gmake pkgconfig
USE_GNOME=	glib20
USE_BZIP2=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/pidgin/pidgin-osd.so \
		lib/pidgin/pidgin-osd.la
pre-configure:
	# Module really needs xosd version 2.2.12 or greater.
	${REINPLACE_CMD} -e 's,2\.2\.14,2.2.12,g' ${WRKSRC}/configure

.include <bsd.port.mk>
