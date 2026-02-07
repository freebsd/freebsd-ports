PORTNAME=	gmp
PORTVERSION=	6.3.0
CATEGORIES=	math devel
MASTER_SITES=	GNU

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Free library for arbitrary precision arithmetic
WWW=		https://gmplib.org/

LICENSE=	LGPL3

USES=		cpe libtool tar:xz pathfix
CPE_VENDOR=	gmplib
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--enable-cxx

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	CPU_OPTS INFO
OPTIONS_DEFAULT=	INFO

CPU_OPTS_DESC=	Enable assembly optimizations for your CPU

INFO_USES=	makeinfo
INFO_CONFIGURE_ENV=	MAKEINFO="${MAKEINFO} --no-split"
INFO_INFO=		gmp

.include <bsd.port.pre.mk>

.if ${ARCH:Mmips*}
MAKE_JOBS_UNSAFE=yes
.endif

.if ! ${PORT_OPTIONS:MCPU_OPTS}
CONFIGURE_ARGS+=--build=${CONFIGURE_TARGET}
.elif ${ARCH:S/64//} != ${ARCH}
.if ${ARCH:Mpowerpc64*}
CONFIGURE_ENV+=	ABI="mode64"
.elif ${ARCH:Mriscv64*}
CONFIGURE_ENV+=	ABI="standard"
.else
CONFIGURE_ENV+=	ABI="64"
.endif
.else
CONFIGURE_ENV+=	ABI="32"
.endif

post-extract-INFO-on:
	@${RM} ${WRKSRC}/doc/gmp.info*

post-patch-INFO-off:
	${REINPLACE_CMD} -e '/^SUBDIRS/ s|doc||' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
