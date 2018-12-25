# $FreeBSD$

PORTNAME=	linphone
PORTVERSION=	3.12.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://www.linphone.org/releases/sources/linphone/
PKGNAMEPREFIX=	lib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SIP library supporting voice/video calls and text messaging

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	doxygen:devel/doxygen \
		${PYTHON_PKGNAMEPREFIX}pystache>=0:textproc/py-pystache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libbelcard.so:deskutils/belcard \
		libbellesip.so:net/belle-sip \
		libbzrtp.so:security/bzrtp \
		libmediastreamer_base.so:net/mediastreamer \
		libortp.so:net/ortp \
		libsqlite3.so:databases/sqlite3

USES=		cmake compiler:c++11-lib gnome iconv pkgconfig \
		python:build
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_NLS=NO -DENABLE_STATIC=NO -DENABLE_STRICT=NO \
		-DENABLE_UNIT_TESTS=NO

OPTIONS_DEFINE=	LDAP VIDEO
OPTIONS_DEFAULT=LDAP VIDEO
OPTIONS_SUB=	yes

LDAP_CMAKE_BOOL=	ENABLE_LDAP
LDAP_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
LDAP_USE=		OPENLDAP=yes

VIDEO_CMAKE_BOOL=	ENABLE_VIDEO

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/${DISTNAME}

.include <bsd.port.mk>
