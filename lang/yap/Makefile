PORTNAME=	yap
PORTVERSION=	6.2.2
PORTREVISION=	11
CATEGORIES=	lang
MASTER_SITES=	https://mirrors.dotsrc.org/mirrors/exherbo/	\
		http://ftp.lyx.org/pub/minix/distfiles/backup/	\
		http://tenampak.izt.uam.mx/programas/

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	High-performance Prolog compiler

LICENSE=		ART20 LGPL20
LICENSE_COMB=		dual
LICENSE_FILE_ART20=	${WRKSRC}/Artistic
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING

#BROKEN_riscv64=		fails to build: procedure chr_translate/2 is undefined, called from context  prolog:once/1

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		gmake localbase readline
PORTSCOUT=	limit:^6\.2\.

OPTIONS_DEFINE=		DOCS BUILDDOCS
BUILDDOCS_DESC=	Rebuild documentation (requires TeX)
DOCS_DESC=	Install documentation

BUILDDOCS_USE=		TEX=formats:build,dvipsk:build
BUILDDOCS_BUILD_DEPENDS=${LOCALBASE}/bin/texi2html:textproc/texi2html \
			${LOCALBASE}/bin/texi2pdf:print/texinfo

DOCS_INSTALL_TARGET=	install install_docs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-max-performance \
		--disable-myddas

DOCSDIR=	${PREFIX}/share/doc/Yap
DATADIR=	${PREFIX}/share/Yap
DOCS_PACKAGE=	yap-doc-${PORTVERSION}

post-build-DOCS-off:
	# prevent the instalation of three docs files
	${REINPLACE_CMD} -e '559,562d' ${WRKSRC}/Makefile

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*}
USES+=		compiler:gcc-c++11-lib
.endif

.if ${PORT_OPTIONS:MDOCS} && !${PORT_OPTIONS:MBUILDDOCS}
MASTER_SITES+=	http://www.grosbein.net/freebsd/distfiles/:docs \
		LOCAL/eugen:docs
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DOCS_PACKAGE}${EXTRACT_SUFX}:docs
.endif

.include <bsd.port.mk>
