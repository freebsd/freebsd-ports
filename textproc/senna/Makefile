# $FreeBSD$

PORTNAME=	senna
PORTVERSION=	1.1.5
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	OSDN/senna

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Embeddable Fulltext Search Engine

BROKEN_aarch64=		does not build: libsenna.so: undefined reference to SEN_ATOMIC_ADD_EX
BROKEN_armv6=		does not build: libsenna.so: undefined reference to SEN_ATOMIC_ADD_EX
BROKEN_armv7=		does not build: libsenna.so: undefined reference to SEN_ATOMIC_ADD_EX
BROKEN_sparc64=		does not build: libsenna.so: undefined reference to SEN_ATOMIC_ADD_EX

USES=		compiler:c11 gmake libtool pathfix
GNU_CONFIGURE=	yes
USE_GCC=	any
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-sennahome=${SENNA_HOME}
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ARGS=	CFLAGS="${CFLAGS}"
WRKSRC=		${WRKDIR}/${DISTNAME}

SENNA_HOME?=	/var/senna

OPTIONS_DEFINE=	MECAB NFKC
OPTIONS_DEFAULT=	MECAB NFKC
MECAB_DESC=	Use MeCab for morphological analysis
NFKC_DESC=	Use NFKC-based UTF-8 normalization

MECAB_LIB_DEPENDS=	libmecab.so:japanese/mecab
MECAB_CONFIGURE_OFF=	--without-mecab

NFKC_CONFIGURE_OFF=	--disable-nfkc

.include <bsd.port.mk>
