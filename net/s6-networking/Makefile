PORTNAME=	s6-networking
DISTVERSION=	2.7.2.1
CATEGORIES=	net
MASTER_SITES=	http://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	crest@rlwinm.de
COMMENT=	Suite of small networking utilities for Unix systems
WWW=		https://www.skarnet.org/software/s6-networking/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	skalibs>=2.14.5.1:devel/skalibs \
		s6>=2.14.0.1:sysutils/s6 \
		s6-dns>=2.4.1.1:dns/s6-dns \
		bearssl>=0.6:security/bearssl
RUN_DEPENDS=	skalibs>=2.14.5.1:devel/skalibs \
		s6>=2.14.0.1:sysutils/s6 \
		s6-dns>=2.4.1.1:dns/s6-dns \
		bearssl>=0.6:security/bearssl
LIB_DEPENDS=	libs6.so:sysutils/s6 \
		libskarnet.so:devel/skalibs \
		libskadns.so:dns/s6-dns \
		libs6dns.so:dns/s6-dns \
		libbearssl.so:security/bearssl

USES=		gmake
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes

CFLAGS+=	-D__BSD_VISIBLE

CONFIGURE_ARGS+=--prefix=${PREFIX} \
	--with-include=${LOCALBASE}/include \
	--with-lib=${LOCALBASE}/lib \
	--with-lib=${LOCALBASE}/lib/execline \
	--with-lib=${LOCALBASE}/lib/s6 \
	--with-dynlib=${LOCALBASE}/lib \
	--enable-ssl=bearssl \
	--with-ssl-path=${LOCALBASE} \
	--enable-shared

DOCS=		AUTHORS COPYING INSTALL README doc/*.html
OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
