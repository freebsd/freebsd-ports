PORTNAME=	liblinphone
DISTVERSION=	5.4.26
CATEGORIES=	net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SIP library supporting voice/video calls and text messaging
WWW=		https://www.linphone.org/technical-corner/liblinphone.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pystache>=0:textproc/py-pystache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		doxygen:devel/doxygen \
		v4l_compat>=1.0.20120501:multimedia/v4l_compat \
		xsd>0:devel/xsd
LIB_DEPENDS=	\
		libbelcard.so:deskutils/belcard \
		libbelle-sip.so:net/belle-sip \
		liblime.so:security/lime \
		libmediastreamer2.so:net/mediastreamer \
		libsoci_core.so:databases/soci

USES=		cmake compiler:c++17-lang gnome iconv pkgconfig python:build \
		sqlite xorg
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_XORG=	xfixes

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DCMAKE_SKIP_INSTALL_RPATH=ON \
		-DENABLE_DAEMON=NO \
		-DENABLE_FLEXIAPI=NO \
		-DENABLE_NLS=NO \
		-DENABLE_QRCODE=NO \
		-DENABLE_STATIC=NO \
		-DENABLE_STRICT=NO \
		-DENABLE_TOOLS=NO
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	ENABLE_UNIT_TESTS

LDFLAGS+=	-lpthread

OPTIONS_DEFINE=		LDAP VIDEO
OPTIONS_DEFAULT=	LDAP VIDEO
OPTIONS_SUB=		yes

LDAP_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
LDAP_USES=		ldap
LDAP_CMAKE_BOOL=	ENABLE_LDAP
VIDEO_CMAKE_BOOL=	ENABLE_VIDEO

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/CMakeLists.txt

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/${DISTNAME}

.include <bsd.port.mk>
