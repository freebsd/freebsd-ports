PORTNAME=	cairo-clock
DISTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	x11-clocks
MASTER_SITES=	http://ftp.de.debian.org/debian/pool/main/c/cairo-clock/
DISTNAME=	${PORTNAME}_${DISTVERSION}.orig

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Analog clock displaying the system-time

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-XML-Parser>0:textproc/p5-XML-Parser
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext gmake gnome iconv perl5 pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 libglade2 pango librsvg2 libxml2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_ARGS=	GMSGFMT=msgfmt DATADIRNAME=share

.include <bsd.port.mk>
