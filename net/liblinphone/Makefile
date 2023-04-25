PORTNAME=	liblinphone
DISTVERSION=	5.2.37
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SIP library supporting voice/video calls and text messaging
WWW=		https://www.linphone.org/technical-corner/liblinphone.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pystache>=0:textproc/py-pystache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		doxygen:devel/doxygen \
		xsd>0:devel/xsd
LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libbelcard.so:deskutils/belcard \
		libbellesip.so:net/belle-sip \
		libbelr.so:textproc/belr \
		libbzrtp.so:security/bzrtp \
		libjsoncpp.so:devel/jsoncpp \
		liblime.so:security/lime \
		libmediastreamer.so:net/mediastreamer \
		libortp.so:net/ortp \
		libsoci_core.so:databases/soci \
		libxerces-c.so:textproc/xerces-c3

USES=		cmake compiler:c++17-lang gnome iconv pkgconfig python:build sqlite
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_COMMIT=	f8c1a652c2e014d1bdec9fc8d2a1996571970a9d
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DCMAKE_SKIP_INSTALL_RPATH=ON \
		-DENABLE_FLEXIAPI=NO \
		-DENABLE_NLS=NO \
		-DENABLE_QRCODE=NO \
		-DENABLE_STATIC=NO \
		-DENABLE_STRICT=NO \
		-DENABLE_UNIT_TESTS=NO

OPTIONS_DEFINE=		LDAP VIDEO
OPTIONS_DEFAULT=	LDAP VIDEO
OPTIONS_SUB=		yes

LDAP_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
LDAP_USES=		ldap
LDAP_CMAKE_BOOL=	ENABLE_LDAP
VIDEO_CMAKE_BOOL=	ENABLE_VIDEO

post-patch:
.for h in xml conference-info conference-info-linphone-extension
	@${REINPLACE_CMD} '/^#error/d' ${WRKSRC}/src/xml/${h}.h
.endfor

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/${DISTNAME}

.include <bsd.port.mk>
