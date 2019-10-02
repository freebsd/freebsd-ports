# Created by: Ulrich Spoerlein <uqs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	groff
PORTVERSION=	1.22.4
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Software typesetting package

LICENSE=	GPLv3

BUILD_DEPENDS=	psselect:print/psutils \
		gsfonts>=0:print/gsfonts
LIB_DEPENDS=	libuchardet.so:textproc/uchardet
RUN_DEPENDS:=	psselect:print/psutils

MAKE_JOBS_UNSAFE=	yes

USES=		cpe gmake perl5 makeinfo
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-urw-fonts-dir=${LOCALBASE}/share/ghostscript/fonts/ \
			--with-awk=/usr/bin/awk \
			--without-x \
			--without-gs \
			pnmcrop=missing \
			pnmcut=missing \
			pnmtopng=missing \
			pnmtops=missing \
			psselect=missing

CPE_VENDOR=	gnu

.ifdef QEMU_EMULATING
# XXX bug 224740: configure hangs: GSlice: failed to allocate 496 bytes (alignment: 512)
CONFIGURE_ENV+=	gl_cv_func_printf_enomem=no
.endif

# Canonicalize to A4 if set.
.if defined(A4) || (defined(PAPERSIZE) && ${PAPERSIZE:tu} == "A4")
PAPERSIZE=A4
.endif
.if defined(PAPERSIZE)
CONFIGURE_ENV+=	PAGE=${PAPERSIZE}
.endif

CONFLICTS=	ja-groff-[0-9]*

INFO=	groff

DATADIR=	${PREFIX}/share/${PORTNAME}/${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
EXAMPLESDIR=	${DOCSDIR}/examples

post-install:
	${INSTALL_DATA} ${FILESDIR}/mdoc.local ${STAGEDIR}${PREFIX}/share/groff/site-tmac
	${REINPLACE_CMD} -i "" -e "s/missing/gs/" ${STAGEDIR}${DATADIR}/font/devhtml/DESC

.include <bsd.port.mk>
