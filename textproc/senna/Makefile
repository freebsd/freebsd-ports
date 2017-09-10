# $FreeBSD$

PORTNAME=	senna
PORTVERSION=	1.1.5
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	SFJP/senna/46945

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Embeddable Fulltext Search Engine

BROKEN_aarch64=		does not build: libsenna.so: undefined reference to SEN_ATOMIC_ADD_EX
BROKEN_armv6=		does not build: libsenna.so: undefined reference to SEN_ATOMIC_ADD_EX
BROKEN_powerpc64=	does not build: relocation truncated to fit: R_PPC64_TOC16_DS
BROKEN_sparc64=		does not build

GNU_CONFIGURE=	YES
USE_GCC=	any
USES=		gmake libtool pathfix
USE_LDCONFIG=	YES
CONFIGURE_ARGS=	--with-sennahome=${SENNA_HOME}
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ARGS=	CFLAGS="${CFLAGS}"
WRKSRC=		${WRKDIR}/${DISTNAME}

SENNA_HOME?=	/var/senna

OPTIONS_DEFINE=	MECAB NFKC
OPTIONS_DEFAULT=	MECAB NFKC
MECAB_DESC=	use mecab for morphological analysis
NFKC_DESC=	use nfkc based utf8 normalization

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMECAB}
CONFIGURE_ARGS+=	--with-mecab
LIB_DEPENDS+=	libmecab.so:japanese/mecab
.else
CONFIGURE_ARGS+=	--without-mecab
.endif

.if ${PORT_OPTIONS:MNFKC}
CONFIGURE_ARGS+=	--disable-nfkc
.endif

.include <bsd.port.mk>
