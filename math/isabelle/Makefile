# Created by: Timothy Bourke <timbob@bigpond.com>
# $FreeBSD$

PORTNAME=	isabelle
PORTVERSION=	2009.2
CATEGORIES=	math
MASTER_SITES=	http://isabelle.in.tum.de/dist/ \
		http://www.cl.cam.ac.uk/Research/HVG/Isabelle/dist/ \
		http://mirror.cse.unsw.edu.au/pub/isabelle/dist/
DISTNAME=	Isabelle2009-2

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Generic proof assistant

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

OPTIONS_DEFINE=	POLYML RLWRAP LEDIT HOL_ALGEBRA HOL_NOMINAL HOL_NSA HOL_WORD \
		HOL_TLA HOL_HOL4 EMACS_PKG
OPTIONS_DEFAULT=	RLWRAP
POLYML_DESC=		Use Poly/ML (fast but broken) instead of SML/NJ
RLWRAP_DESC=		Use rlwrap as line editor
LEDIT_DESC=		Use ledit as line editor
HOL_ALGEBRA_DESC=	Build optional heap: HOL-Algebra
HOL_NOMINAL_DESC=	Build optional heap: HOL-Nominal
HOL_NSA_DESC=		Build optional heap: HOL-NSA
HOL_WORD_DESC=		Build optional heap: HOL-Word
HOL_TLA_DESC=		Build optional heap: TLA
HOL_HOL4_DESC=		Build optional heap: HOL4
EMACS_PKG_DESC=		Build with Emacs Packages

USES=		perl5

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES=	${DISTNAME}.tar.gz \
		${DISTNAME}_library.tar.gz
.endif

.if ${PORT_OPTIONS:MEMACS_PKG}
USE_EMACS=	yes # for EMACS_SITE_LISPDIR
EMACS_NO_BUILD_DEPENDS=yes
EMACS_NO_RUN_DEPENDS=yes
RUN_DEPENDS+=	proofgeneral:${PORTSDIR}/math/proofgeneral
.else
.endif

BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash

DOCFILES=	Contents *.pdf *.eps *.ps *.dvi

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MRLWRAP}
RUN_DEPENDS+=	rlwrap:${PORTSDIR}/devel/rlwrap
LINE_EDIT=	"${PREFIX}/bin/rlwrap"
.else
.if ${PORT_OPTIONS:MLEDIT}
RUN_DEPENDS+=	ledit:${PORTSDIR}/sysutils/ledit
LINE_EDIT=	"${PREFIX}/bin/ledit"
.else
LINE_EDIT=	""
.endif
.endif

.if ${PORT_OPTIONS:MHOL_ALGEBRA}
HEAP_HOL_ALGEBRA=""
EXTRA_HOL+=-m HOL-Algebra
.else
HEAP_HOL_ALGEBRA="@comment "
.endif
.if ${PORT_OPTIONS:MHOL_NOMINAL}
HEAP_HOL_NOMINAL=""
EXTRA_HOL+=-m HOL-Nominal
.else
HEAP_HOL_NOMINAL="@comment "
.endif
.if ${PORT_OPTIONS:MHOL_NSA}
HEAP_HOL_NSA=""
EXTRA_HOL+=-m HOL-NSA
.else
HEAP_HOL_NSA="@comment "
.endif
.if ${PORT_OPTIONS:MHOL_WORD}
HEAP_HOL_WORD=""
EXTRA_HOL+=-m HOL-Word
.else
HEAP_HOL_WORD="@comment "
.endif
.if ${PORT_OPTIONS:MHOL_TLA}
HEAP_HOL_TLA=""
EXTRA_HOL+=-m TLA
.else
HEAP_HOL_TLA="@comment "
.endif
.if ${PORT_OPTIONS:MHOL_HOL4}
HEAP_HOL_HOL4=""
EXTRA_HOL+=-m HOL4
.else
HEAP_HOL_HOL4="@comment "
.endif

.if ! ${PORT_OPTIONS:MPOLYML}
ML_SYSTEM=	smlnj-110
ML_HOME=	${LOCALBASE}/smlnj/bin
ML_OPTIONS=	-Ccontrol.poly-eq-warn=false @SMLdebug=/dev/null
.else
ML_SYSTEM=	polyml-5.3
ML_HOME=	${LOCALBASE}/bin
ML_OPTIONS=	-H 500
ML_DBASE=	""
.endif
ML_PLATFORM=	x86-bsd

PLIST_SUB+=	HEAPSUBDIR=${ML_SYSTEM}_${ML_PLATFORM} \
		HEAP_HOL_ALGEBRA=${HEAP_HOL_ALGEBRA} \
		HEAP_HOL_NOMINAL=${HEAP_HOL_NOMINAL} \
		HEAP_HOL_NSA=${HEAP_HOL_NSA} \
		HEAP_HOL_WORD=${HEAP_HOL_WORD} \
		HEAP_HOL_TLA=${HEAP_HOL_TLA} \
		HEAP_HOL_HOL4=${HEAP_HOL_HOL4}
.if ! ${PORT_OPTIONS:MPOLYML}
BUILD_DEPENDS+=	smlnj-devel>=110.71:${PORTSDIR}/lang/sml-nj-devel
MAKE_ENV+=	SMLNJ_DEVEL=yes
.else
BUILD_DEPENDS+=	polyml>=5.2.1:${PORTSDIR}/lang/polyml
RUN_DEPENDS+=	polyml>=5.2.1:${PORTSDIR}/lang/polyml
.endif

NO_INSTALL_MANPAGES=yes

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-patch:
	@${MV} ${WRKSRC}/etc/settings ${WRKSRC}/etc/settings.presed
	@${SED} "s|%%ML_SYSTEM%%|${ML_SYSTEM}|;		\
		 s|%%ML_HOME%%|${ML_HOME}|;		\
		 s|%%ML_OPTIONS%%|\"${ML_OPTIONS}\"|;	\
		 s|%%ML_DBASE%%|${ML_DBASE}|;		\
		 s|%%ML_PLATFORM%%|${ML_PLATFORM}|;	\
		 s|%%PREFIX%%|${PREFIX}|;		\
		 s|%%LINE_EDIT%%|${LINE_EDIT}|;		\
		 s|%%SYSTMPDIR%%|/tmp|;			\
		 s|%%JAVASHAREDIR%%|${PREFIX}/share/java|;	\
		 s|%%EMACS_SITE_LISPDIR%%|${EMACS_SITE_LISPDIR}|" \
		${WRKSRC}/etc/settings.presed > ${WRKSRC}/etc/settings
	@${RM} ${WRKSRC}/etc/settings.presed
	@${TOUCH} ${WRKSRC}/contrib/.keep
	@${REINPLACE_CMD} -e 's|%%SMLNJ_VERSION%%|SMLNJ_DEVEL=yes|' \
			${WRKSRC}/lib/scripts/run-smlnj

post-build:
.if defined(EXTRA_HOL)
	${WRKSRC}/build -b ${EXTRA_HOL} HOL
.endif

post-install:
	${WRKSRC}/bin/isabelle install \
		-d ${PREFIX}/share/isabelle \
		-p ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
	(cd ${WRKSRC}; \
	 ${FIND} -d browser_info -type d -exec ${MKDIR} ${DOCSDIR}/{} \; ; \
	 ${FIND} -d browser_info -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;)
.endif

.include <bsd.port.post.mk>
