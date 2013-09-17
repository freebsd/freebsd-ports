# Created by: Ulrich Spoerlein <uqs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	groff
PORTVERSION=	1.21
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	groff

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	Software typesetting package

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/bin/gs:${PORTSDIR}/print/ghostscript8 \
		${LOCALBASE}/bin/psselect:${PORTSDIR}/print/psutils
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-awk=/usr/bin/awk

# Canonicalize to A4 if set.
.if defined(A4) || (defined(PAPERSIZE) && ${PAPERSIZE:U} == "A4")
PAPERSIZE=A4
.endif
.if defined(PAPERSIZE)
CONFIGURE_ENV+=	PAGE=${PAPERSIZE}
.endif

OPTIONS_DEFINE=	X11
X11_DESC=	X11 devices (-TX*) and gxditview
OPTIONS_DEFAULT=	X11

CONFLICTS=	ja-groff-[0-9]*

INFO=	groff
MAN1=	addftinfo.1 afmtodit.1 chem.1 eqn.1 eqn2graph.1 gdiffmk.1 \
	grap2graph.1 grn.1 grodvi.1 groff.1 groffer.1 grog.1 grohtml.1 \
	grolbp.1 grolj4.1 grops.1 grotty.1 hpftodit.1 indxbib.1 lkbib.1 \
	lookbib.1 mmroff.1 neqn.1 nroff.1 pdfroff.1 pfbtops.1 pic.1 \
	pic2graph.1 preconv.1 refer.1 roff2dvi.1 roff2html.1 roff2pdf.1 \
	roff2ps.1 roff2text.1 roff2x.1 soelim.1 tbl.1 tfmtodit.1 troff.1
MAN5=	groff_font.5 groff_out.5 groff_tmac.5 lj4_font.5
MAN7=	ditroff.7 groff.7 groff_char.7 groff_diff.7 groff_hdtbl.7 \
	groff_man.7 groff_mdoc.7 groff_me.7 groff_mm.7 groff_mmse.7 \
	groff_mom.7 groff_ms.7 groff_trace.7 groff_www.7 roff.7

DATADIR=	${PREFIX}/share/${PORTNAME}/${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
EXAMPLESDIR=	${DOCSDIR}/examples

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=--without-x
PLIST_SUB+=	X11="@comment "
.if exists(${LOCALBASE}/bin/pnmcut) && exists(${LOCALBASE}/bin/pnmcrop) && \
    exists(${LOCALBASE}/bin/pnmtops) && exists(${LOCALBASE}/bin/pnmtopng)
PLIST_SUB+=	HTMLDOCS=""
.else
PLIST_SUB+=	HTMLDOCS="@comment "
.endif
.else
USE_XORG=	x11 xaw xmu
BUILD_DEPENDS+=	${LOCALBASE}/bin/pnmtops:${PORTSDIR}/graphics/netpbm
RUN_DEPENDS+=	${LOCALBASE}/bin/pnmtops:${PORTSDIR}/graphics/netpbm
CONFIGURE_ARGS+=--with-x --with-appresdir=${PREFIX}/lib/X11/app-defaults
PLIST_SUB+=	X11=""
PLIST_SUB+=	HTMLDOCS=""
MAN1+=		gxditview.1 xtotroff.1
.endif

# Run in src/libs/gnulib subdir, too
post-configure:
	@(cd ${WRKSRC}/src/libs/gnulib && \
	    ${SET_LATE_CONFIGURE_ARGS} \
	    if ! ${SETENV} CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
	    CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	    INSTALL="/usr/bin/install -c ${_BINOWNGRP}" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_LIB="${INSTALL_LIB}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; then \
		 ${ECHO_MSG} "===>  Script \"${CONFIGURE_SCRIPT}\" failed unexpectedly."; \
		 (${ECHO_CMD} ${CONFIGURE_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
		 ${FALSE}; \
	    fi)

post-install:
	${INSTALL_DATA} ${FILESDIR}/mdoc.local ${PREFIX}/share/groff/site-tmac

.include <bsd.port.post.mk>
