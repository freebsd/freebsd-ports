PORTNAME=	mswebrtc
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	multimedia net
MASTER_SITES=	https://www.linphone.org/releases/sources/plugins/mswebrtc/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Mediastreamer plugin with WebRTC codecs
WWW=		https://www.linphone.org/technical-corner/mediastreamer2.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

#BROKEN=		does not build: incorrect dependency on net/mediastreamer

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libmediastreamer.so:net/mediastreamer \
		libortp.so:net/ortp

USES=		cmake compiler:c++11-lib
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public public/external:webrtc
GL_PROJECT=	webrtc:webrtc
GL_COMMIT=	80b8e33b11516870b887b80279b9da4de8b26ebe \
			583acd27665cfadef8ab03eb85a768d308bd29dd:webrtc
GL_SUBDIR=	webrtc:webrtc

CMAKE_ARGS=	-DENABLE_STATIC=NO
PLIST_FILES=	lib/mediastreamer/plugins/libmswebrtc.so

.include <bsd.port.mk>
