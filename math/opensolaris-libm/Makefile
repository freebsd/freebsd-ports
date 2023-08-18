PORTNAME=	opensolaris-libm
PORTVERSION=	2006.01.31
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C99 Math and vector libraries from OpenSolaris snv_33
WWW=		https://docs.oracle.com/cd/E19422-01/819-3693/ncg_lib.html

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/usr/src/OPENSOLARIS.LICENSE

BROKEN_FreeBSD_14=	fails to compile: conflicting types for 'lround'
ONLY_FOR_ARCHS=	amd64	# i386 possible with much work

PORTSCOUT=	ignore:1

USE_GITHUB=	yes
GH_ACCOUNT=	jrmarino
GH_TAGNAME=	2017.01.31

BUILD_WRKSRC=	${WRKSRC}/usr/src/libm/wos64
INSTALL_WRKSRC=	${WRKSRC}/usr/src/libm/wos64
MAKEFILE=	Makefile.bsd
MAKE_ENV=	ARCH=${ARCH} USE_ASSEMBLY_VERSIONS=yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
RUN_DEPENDS=	${LOCALBASE}/bin/addr2line:devel/binutils

post-patch:
	# The addr2line program in FreeBSD is inadequate, so pull in
	# binutils on FreeBSD
	@${REINPLACE_CMD} -e 's|/usr/bin|/usr/local/bin|' \
		${WRKSRC}/usr/src/libm/src/m9x/__traceback.c
.endif

.include <bsd.port.mk>
