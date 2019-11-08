# Created by: sahne
# $FreeBSD$

PORTNAME=	lxde-common
PORTVERSION=	0.99.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SF/lxde/${PORTNAME}%20%28default%20config%29/${PORTNAME}%20${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LXDE Common files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	lxde-icon-theme>=0:x11-themes/lxde-icon-theme \
		gnome-themes-extra>=3.18:x11-themes/gnome-themes-extra \
		xscreensaver:x11/xscreensaver

USES=		gettext-tools gmake gnome localbase tar:xz
USE_GNOME=	gtk20 intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-xsession-path=${PREFIX}/share/xsessions
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/lxde
INSTALLS_ICONS=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/desktop.conf \
		${STAGEDIR}${PREFIX}/etc/xdg/lxsession/LXDE/desktop.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pcmanfm/pcmanfm.conf \
		${STAGEDIR}${PREFIX}/etc/xdg/pcmanfm/LXDE/pcmanfm.conf.sample

.include <bsd.port.mk>
