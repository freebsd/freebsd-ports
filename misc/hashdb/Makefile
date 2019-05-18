# $FreeBSD$

PORTNAME=	hashdb
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0-8
DISTVERSIONSUFFIX=	-g1da1b9f
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Block hash database tool and API

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	swig3.0:devel/swig30 \
		openssl>0:security/openssl
LIB_DEPENDS=	libewf.so:devel/libewf
RUN_DEPENDS=	openssl>0:security/openssl

USES=		autoreconf gmake libtool localbase:ldflags python ssl # USES=ssl fails without openssl added to BUILD_DEPENDS/RUN_DEPENDS/LDFLAGS: see bug#237974
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	NPS-DEEP
CONFIGURE_ARGS=	--disable-static --enable-shared # this fails: https://github.com/NPS-DEEP/hashdb/issues/9

INSTALL_TARGET=	install-strip

CONFIGURE_ENV=	PYTHON=${PYTHON_CMD}
BINARY_ALIAS=	swig=${LOCALBASE}/bin/swig3.0

CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC
LDFLAGS+=	${LOCALBASE}/lib/libssl.so ${LOCALBASE}/lib/libcrypto.so

PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}

post-configure:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} 's| -lstdc++ | |'

.include <bsd.port.mk>
