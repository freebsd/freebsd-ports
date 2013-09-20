# Created by: Timothy Bourke <timbob@bigpond.com>
# $FreeBSD$

PORTNAME=	sml-fxp
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www2.informatik.tu-muenchen.de/~berlea/Fxp/ \
		http://www.tbrk.org/distfiles/
DISTNAME=	fxp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Validating XML parser with Standard ML interface

# DEVEL MLTON STABILIZATION  Result
#  Off   Off     Off         build apps with sml-nj (no stabilization)
#  On    Off     Off         build apps with sml-nj-devel (no stabilization)
#  Off   On      Off         build apps with mlton (no stabilization)
#  On    On      Off         as above
#  Off   Off     On          build apps and stabilize with sml-nj
#  On    Off     On          build apps and stabilize with sml-nj-devel
#  Off   On      On          apps with mlton, stabilize for sml-nj
#  On    On      On          apps with mlton, stabilize for sml-nj-devel
OPTIONS_DEFINE=	X11 STABILIZATION DEVEL MLTON DOCS
OPTIONS_DEFAULT=	X11 STABILIZATION DEVEL
STABILIZATION_DESC=	Stabilize the libraries for SML/NJ.
DEVEL_DESC=	Prefer the devel version of SML/NJ.
MLTON_DESC=	Build executables with mlton.

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	xvcg:${PORTSDIR}/graphics/vcg
.endif

.if ${PORT_OPTIONS:MSTABILITATION} || empty(PORT_OPTIONS:MMLTON)
.if ${PORT_OPTIONS:MDEVEL}
BUILD_DEPENDS+=	smlnj-devel>=110.65:${PORTSDIR}/lang/sml-nj-devel

MAKE_ENV+=	SMLNJ_DEVEL=yes
.else
BUILD_DEPENDS+=	smlnj>=0:${PORTSDIR}/lang/sml-nj
RUN_DEPENDS+=	smlnj>=0:${PORTSDIR}/lang/sml-nj

MAKE_ENV+=	SMLNJ=yes
.endif
.endif

.if ${PORT_OPTIONS:MMLTON}
PLIST_SUB+=	SML_EXEC="@comment " SML_EXEC_DEVEL="@comment "
.elif ${PORT_OPTIONS:MDEVEL}
PLIST_SUB+=	SML_EXEC="@comment " SML_EXEC_DEVEL=""
.else
PLIST_SUB+=	SML_EXEC="" SML_EXEC_DEVEL="@comment "
.endif

.if ${PORT_OPTIONS:MSTABILIZATION}
MAKE_ENV+=	STABILIZE=yes

.if ${PORT_OPTIONS:MDEVEL}
PLIST_SUB+=	STABLE="@comment " STABLE_DEVEL=""
.else
PLIST_SUB+=	STABLE="" STABLE_DEVEL="@comment "
.endif

.else
PLIST_SUB+=	STABLE="@comment " STABLE_DEVEL="@comment "
.endif

.if ${PORT_OPTIONS:MSTABILITATION} || !empty(PORT_OPTIONS:MDEVEL)
RUN_DEPENDS+=	smlnj-devel>=110.65:${PORTSDIR}/lang/sml-nj-devel
.endif

.if ${PORT_OPTIONS:MMLTON}
BUILD_DEPENDS+=	mlton:${PORTSDIR}/lang/mlton
MAKE_ENV+=	MLTON_BUILD=yes
.endif

.if empty(PORT_OPTIONS:MMLTON) &&  empty(PORT_OPTIONS:MDEVEL)
MAKE_ENV+=	NO_HEAP2EXEC=yes
PLIST_SUB+=	SML_EXEC=""
.else
PLIST_SUB+=	SML_EXEC="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET=install install-doc
.endif

#
# Installation rationale and compromises
#
# * fxp applications are installed
#   sml-nj: script + heap file, sml-nj-devel/mlton: binary
#
# * fxp source code is installed
#   Making this optional would further complicate the port.
#   The porter currently believes that fxp is of primary interest to sml
#   developers. He is willing to consider otherwise.
#
# * source code for Apps is not installed
#   The Apps do not belong to the library proper (but they are useful as
#   examples).
#
# * a single cm library file is installed (if stabilization occurs)
#   for efficient operation of library consumers written in SML/NJ.
#   The other .cm file and directories would make recompilation faster,
#   but are otherwise unnecessary.
#
# Note: reinstallation of SML/NJ seems to require restabilisation of
#       libraries.
#

post-extract:
	@for f in $$(${LS} ${FILESDIR}/src-*); do			\
		e=$$(${ECHO} $$f|${SED} 's|^${FILESDIR}/\(.*\)|\1|;	\
					 s|-|/|g');			\
		${CP} $$f ${WRKSRC}/$$e;				\
	done

post-patch:
	@for f in $$(${LS} ${FILESDIR}/patch-*.sml); do			      \
		e=$$(${ECHO} $$f|${SED} 's|^${FILESDIR}/patch-\(.*\).sml|\1|; \
					 s|-|/|g');			      \
		${MV} ${WRKSRC}/$$e.sml.orig ${WRKSRC}/$$e.orig.sml;	      \
	done

.include <bsd.port.mk>
