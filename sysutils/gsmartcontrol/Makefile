# Created by: Pawel Pekala <c0rn@o2.pl>
# $FreeBSD$

PORTNAME=	gsmartcontrol
PORTVERSION=	0.8.7
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://artificialtime.com/${PORTNAME}/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Graphical user interface for smartmontools

LIB_DEPENDS=	libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		smartctl:${PORTSDIR}/sysutils/smartmontools

USE_AUTOTOOLS=	libtool
USES=		pkgconfig tar:bzip2
INSTALLS_ICONS=	yes

CONFIGURE_ARGS=	--disable-libglade

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
