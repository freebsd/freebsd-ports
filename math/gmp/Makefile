# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmp
PORTVERSION=	6.2.0
CATEGORIES=	math devel
MASTER_SITES=	GNU

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Free library for arbitrary precision arithmetic

LICENSE=	LGPL3

USES=		libtool makeinfo tar:xz

OPTIONS_DEFINE=	CPU_OPTS
CPU_OPTS_DESC=	Enable assembly optimizations for your CPU

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="${MAKEINFO} --no-split"
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--infodir=${PREFIX}/${INFO_PATH} \
		--mandir=${PREFIX}/man \
		--enable-cxx

USE_LDCONFIG=	yes

INFO=		gmp

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.pre.mk>

.if ${ARCH:Mmips*}
MAKE_JOBS_UNSAFE=yes
.endif

.if ! ${PORT_OPTIONS:MCPU_OPTS}
CONFIGURE_ARGS+=--build=${CONFIGURE_TARGET}
.elif ${ARCH:S/64//} != ${ARCH}
.if ${ARCH} == powerpc64
CONFIGURE_ENV+=	ABI="mode64"
.else
CONFIGURE_ENV+=	ABI="64"
.endif
.else
CONFIGURE_ENV+=	ABI="32"
.endif

post-extract:
	@${RM} ${WRKSRC}/doc/gmp.info*

.include <bsd.port.post.mk>
