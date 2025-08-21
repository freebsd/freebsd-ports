PORTNAME=	libixion
DISTVERSION=	0.20.0
CATEGORIES=	textproc
#MASTER_SITES=	https://kohei.us/files/ixion/src/

PATCH_SITES+=	https://gitlab.com/ixion/ixion/-/commit/
PATCHFILES+=	bfe5ab6adadda265d575fec9c192e6f53f2ef9f5.diff:-p1 \
		d1ee97a73027579dd988d96d7a154f38c3187f37.diff:-p1

MAINTAINER=	office@FreeBSD.org
COMMENT=	General purpose formula parser, interpreter, dependency tracker
WWW=		https://gitlab.com/ixion/ixion

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mdds>=${MDDS_VERSION}:devel/mdds
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs

USES=		autoreconf libtool localbase pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	ixion
GL_PROJECT=	ixion

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=${DISTVERSION:R}

CONFIGURE_ARGS=	--disable-python

MDDS_VERSION=	3.1

post-patch:
	${REINPLACE_CMD} -e 's/mdds-3.0/mdds-${MDDS_VERSION}/' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
