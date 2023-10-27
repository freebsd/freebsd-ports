PORTNAME=	ump
PORTVERSION=	0.8.6
PORTREVISION=	14
CATEGORIES=	math education
MASTER_SITES=	SF/u-m-p/u-m-p/${PORTVERSION}
PKGNAMESUFFIX=	-math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical, easy to use math program
WWW=		https://u-m-p.sourceforge.net/

LICENSE=	GPLv2

USES=		compiler:c++11-lang gl gmake gnome pkgconfig tar:bzip2 xorg
USE_CXXSTD=	c++14
USE_GL=		gl glu
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_XORG=	x11

ALL_TARGET=	${PORTNAME}

CONFLICTS=	ump-1.[0-9]*

DESKTOP_ENTRIES="Ump" "" "" "ump" "Education;Math;Science;GTK;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/src/main.cpp

post-install:
	${INSTALL_DATA} ${WRKSRC}/ump.conf \
		${STAGEDIR}${PREFIX}/etc/ump.conf.sample

.include <bsd.port.mk>
