PORTNAME=	opensolaris-libm
PORTVERSION=	2006.01.31
PORTREVISION=	5
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C99 Math and vector libraries from OpenSolaris snv_33

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/usr/src/OPENSOLARIS.LICENSE

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
