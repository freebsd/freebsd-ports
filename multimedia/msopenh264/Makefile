PORTNAME=	msopenh264
DISTVERSION=	1.2.1-20220531
PORTREVISION=	1
CATEGORIES=	multimedia net
#MASTER_SITES=	https://www.linphone.org/releases/sources/plugins/msopenh264/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mediastreamer plugin with H.264 codec
WWW=		https://www.linphone.org/technical-corner/mediastreamer2.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libmediastreamer.so:net/mediastreamer \
		libopenh264.so:multimedia/openh264 \
		libortp.so:net/ortp

USES=		cmake

USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_COMMIT=	c09d2652245f0d660f427c1cf5ae97709b504803

CMAKE_ARGS=	-DENABLE_STATIC=NO
PLIST_FILES=	lib/mediastreamer/plugins/libmsopenh264.so

.include <bsd.port.mk>
