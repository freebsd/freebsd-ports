PORTNAME=	batterycat
PORTVERSION=	1.6
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/source_tarball
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical battery monitoring tool

LICENSE=	GPLv2+

USES=		gmake gnome pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk20

PLIST_FILES=	bin/batterycat share/applications/batterycat.desktop \
		${DATADIR_REL}/batterycat.html \
		${DATADIR_REL}/batterycat_128.xpm \
		${DATADIR_REL}/batterycat_32.xpm

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext-tools
NLS_MAKE_ENV=	WITH_NLS=yes
NLS_PLIST_FILES=	share/locale/de/LC_MESSAGES/batterycat.mo \
		share/locale/fr/LC_MESSAGES/batterycat.mo

post-patch:
	@${REINPLACE_CMD} -e 's,^struct BATTERY_DATA,extern &,' \
		${WRKSRC}/history.c

.include <bsd.port.mk>
