# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	encfs
PORTVERSION=	1.7.4
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Encrypted pass-through FUSE filesystem

LIB_DEPENDS=	librlog.so:${PORTSDIR}/devel/rlog \
		libboost_serialization.so:${PORTSDIR}/devel/boost-libs

WRKSRC=		${WRKDIR}/encfs-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost-serialization=boost_serialization \
		--with-boost-system=boost_system \
		--with-boost-filesystem=boost_filesystem
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		fuse gmake libtool pkgconfig tar:tgz
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} '/OPENSSL_LIBS=/s/-lssl/& -lcrypto/' \
		${WRKSRC}/configure
	@${FIND} ${WRKSRC}/encfs -type f | ${XARGS} ${REINPLACE_CMD} -E \
		's/(^|[[:space:]])(shared_ptr)/\1boost::\2/g'

.include <bsd.port.mk>
