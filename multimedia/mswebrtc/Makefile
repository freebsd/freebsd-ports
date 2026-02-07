PORTNAME=	mswebrtc
DISTVERSION=	5.4.0
PORTREVISION=	1
CATEGORIES=	multimedia net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Mediastreamer plugin with WebRTC codecs
WWW=		https://www.linphone.org/technical-corner/mediastreamer2.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>=1.0.20120501:multimedia/v4l_compat
LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libmediastreamer2.so:net/mediastreamer

USES=		cmake compiler:c++11-lib
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_TUPLE=	https://gitlab.linphone.org/BC/public:external:webrtc:583acd27665cfadef8ab03eb85a768d308bd29dd:webrtc/webrtc

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_FILES=	lib/mediastreamer/plugins/libmswebrtc.so

#post-patch:
#	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
