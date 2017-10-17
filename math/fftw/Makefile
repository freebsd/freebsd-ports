# Created by: Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
# $FreeBSD$

PORTNAME=	fftw
PORTVERSION=	2.1.5
PORTREVISION?=	15
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.fftw.org/pub/fftw/ 		\
		ftp://ftp.fftw.org/pub/fftw/old/ 	\
		ftp://theory.lcs.mit.edu/pub/fftw/	\
		ftp://pm.cse.rmit.edu.au/pub/dsp/fftw/

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Fast C routines to compute the Discrete Fourier Transform

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

# current flavors: default, float
FFTW_FLAVOR?=	default

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
USES=		fortran gmake libtool:keepla
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_SUB=	FFTW_SUFX="${FFTW_SUFX}"

PORTSCOUT=	limit:^2\.

.if ${FFTW_FLAVOR}=="float"
CONFIGURE_ARGS+=	--enable-float --enable-type-prefix
FFTW_SUFX=		s
PKGNAMESUFFIX=		-float
.else
USES+=			makeinfo
FFTW_SUFIX=
INFO=			fftw
.endif

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-i386-hacks
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc | |' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^LINK/s|$$(CCLD)|& -Wc,-B${LOCALBASE}/bin|' \
		${WRKSRC}/fftw/Makefile.in ${WRKSRC}/mpi/Makefile.in \
		${WRKSRC}/rfftw/Makefile.in ${WRKSRC}/threads/Makefile.in

.if ${FFTW_FLAVOR}=="default"
post-build:
	@cd ${WRKSRC}/doc && makeinfo fftw.texi
.endif

.if ${FFTW_FLAVOR}=="default"
post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/fftw.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/fftw.ps ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
