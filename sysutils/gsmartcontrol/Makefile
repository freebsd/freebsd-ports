# Created by: Pawel Pekala <c0rn@o2.pl>
# $FreeBSD$

PORTNAME=	gsmartcontrol
PORTVERSION=	0.8.7
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://artificialtime.com/${PORTNAME}/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Graphical user interface for smartmontools

LIB_DEPENDS=	libgtkmm-2.4.so:x11-toolkits/gtkmm24
RUN_DEPENDS=	bash:shells/bash \
		smartctl:sysutils/smartmontools

USES=		compiler:c++11-lang pkgconfig tar:bzip2 libtool
USE_CXXSTD=	c++11
INSTALLS_ICONS=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-libglade

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
