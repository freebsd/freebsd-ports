PORTNAME=	liblinphone
DISTVERSION=	5.1.32
CATEGORIES=	net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SIP library supporting voice/video calls and text messaging

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

USES=		cmake gnome iconv pkgconfig python:build sqlite
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_COMMIT=	05b13b98229fc69ed3075916857dbe32b60b2b39
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DCMAKE_SKIP_INSTALL_RPATH=ON \
		-DENABLE_FLEXIAPI=NO \
		-DENABLE_NLS=NO \
		-DENABLE_STATIC=NO \
		-DENABLE_STRICT=NO \
		-DENABLE_UNIT_TESTS=NO

OPTIONS_DEFINE=		LDAP VIDEO
OPTIONS_DEFAULT=	LDAP VIDEO
OPTIONS_SUB=		yes

LDAP_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
LDAP_USE=		OPENLDAP=yes
LDAP_CMAKE_BOOL=	ENABLE_LDAP
VIDEO_CMAKE_BOOL=	ENABLE_VIDEO

post-patch:
.for h in xml conference-info conference-info-linphone-extension
	@${REINPLACE_CMD} '/^#error/d' ${WRKSRC}/src/xml/${h}.h
.endfor

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/${DISTNAME}

.include <bsd.port.mk>
