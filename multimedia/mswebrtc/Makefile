PORTNAME=	mswebrtc
DISTVERSION=	5.4.0
CATEGORIES=	multimedia net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Mediastreamer plugin with WebRTC codecs
WWW=		https://www.linphone.org/technical-corner/mediastreamer2.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/libbctoolbox.a:net/bctoolbox \
		${LOCALBASE}/lib/libbcunit.a:devel/bcunit \
		${LOCALBASE}/lib/libbcmatroska2.a:multimedia/bcmatroska2 \
		${LOCALBASE}/lib/libbzrtp.a:security/bzrtp \
		${LOCALBASE}/lib/libmediastreamer2.a:net/mediastreamer \
		${LOCALBASE}/lib/libortp.a:net/ortp \
		v4l_compat>=1.0.20120501:multimedia/v4l_compat

USES=		cmake compiler:c++11-lib
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_TUPLE=	https://gitlab.linphone.org/BC/public:external:webrtc:583acd27665cfadef8ab03eb85a768d308bd29dd:webrtc/webrtc

CMAKE_ARGS=	-DENABLE_STATIC=NO
PLIST_FILES=	lib/libmswebrtc.a

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
