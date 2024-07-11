PORTNAME=	yap
PORTVERSION=	6.2.2
PORTREVISION=	11
CATEGORIES=	lang
MASTER_SITES=	https://mirrors.dotsrc.org/mirrors/exherbo/	\
		http://ftp.lyx.org/pub/minix/distfiles/backup/	\
		http://tenampak.izt.uam.mx/programas/

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	High-performance Prolog compiler
WWW=		http://www.dcc.fc.up.pt/~vsc/Yap/

LICENSE=		ART20 LGPL20
LICENSE_COMB=		dual
LICENSE_FILE_ART20=	${WRKSRC}/Artistic
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING

#BROKEN_riscv64=		fails to build: procedure chr_translate/2 is undefined, called from context  prolog:once/1

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		compiler:features gmake localbase readline

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-max-performance \
		--disable-myddas

DATADIR=	${PREFIX}/share/Yap
DOCSDIR=	${PREFIX}/share/doc/Yap
PORTSCOUT=	limit:^6\.2\.

OPTIONS_DEFINE=		DOCS BUILDDOCS

BUILDDOCS_DESC=	Rebuild documentation (requires TeX)
DOCS_DESC=	Install documentation

BUILDDOCS_BROKEN=	Fatal error occurred, no output PDF file produced
BUILDDOCS_BUILD_DEPENDS=${LOCALBASE}/bin/texi2html:textproc/texi2html \
			${LOCALBASE}/bin/texi2pdf:print/texinfo
BUILDDOCS_USES=		tex
BUILDDOCS_USE=		TEX=formats:build,dvipsk:build

DOCS_INSTALL_TARGET=	install install_docs

DOCS_PACKAGE=	yap-doc-${PORTVERSION}

post-build-DOCS-off:
	# prevent the instalation of three docs files
	${REINPLACE_CMD} -e '559,562d' ${WRKSRC}/Makefile

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-incompatible-function-pointer-types
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}"
.endif

.if ${OPSYS} == FreeBSD && ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 180
pre-configure:
	${REINPLACE_CMD} 's/ -export-dynamic/ -Wl,--export-dynamic/' \
		${WRKSRC}/configure ${WRKSRC}/packages/cplint/slipcase/Makefile.in
.endif

.if ${ARCH:Mpowerpc*}
USES+=		compiler:gcc-c++11-lib
.endif

.if ${PORT_OPTIONS:MDOCS} && !${PORT_OPTIONS:MBUILDDOCS}
MASTER_SITES+=	http://www.grosbein.net/freebsd/distfiles/:docs \
		LOCAL/eugen:docs
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DOCS_PACKAGE}${EXTRACT_SUFX}:docs
.endif

.include <bsd.port.post.mk>
