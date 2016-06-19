# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	encfs
PORTVERSION=	1.8.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	dg@syrec.org
COMMENT=	Encrypted pass-through FUSE filesystem

LICENSE=	GPLv3

LIB_DEPENDS=	librlog.so:devel/rlog \
		libboost_serialization.so:devel/boost-libs

BROKEN_powerpc64=	does not build
BROKEN_sparc64=		cannot link with boost

WRKSRC=		${WRKDIR}/encfs-${PORTVERSION}

USES=		compiler:c++11-lib fuse autoreconf libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	vgough
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost-serialization=boost_serialization
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

pre-configure:
	@${REINPLACE_CMD} '/OPENSSL_LIBS=/s/-lssl/& -lcrypto/' \
		${WRKSRC}/configure.ac

.include <bsd.port.mk>
