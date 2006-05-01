# New ports collection makefile for:   isabelle
# Date created:        08 August 2005
# Whom:                Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	isabelle
PORTVERSION=	2005
CATEGORIES=	math
MASTER_SITES=	http://isabelle.in.tum.de/dist/ \
		http://www.cl.cam.ac.uk/Research/HVG/Isabelle/dist/ \
		http://mirror.cse.unsw.edu.au/pub/isabelle/dist/
DISTNAME=	Isabelle2005
.if !defined(NOPORTDOCS)
DISTFILES=	Isabelle2005.tar.gz \
		Isabelle2005_library.tar.gz \
		Isabelle2005_pdf.tar.gz
.endif

MAINTAINER=	timbob@bigpond.com
COMMENT=	A generic proof assistant

OPTIONS=	SMLNJ "Use SML/NJ (devel) instead of the faster Poly/ML" Off

.include <bsd.port.pre.mk>

.if defined(WITH_SMLNJ)
ML_SYSTEM=	smlnj-110
ML_HOME=	${LOCALBASE}/smlnj/bin
ML_OPTIONS=	@SMLdebug=/dev/null
.else
ML_SYSTEM=	polyml-4.2.0
ML_HOME=	${LOCALBASE}/lib/polyml/
ML_OPTIONS=	-H 80
ML_DBASE=	""
.endif

USE_PERL5=	yes
BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS+=	proofgeneral:${PORTSDIR}/math/proofgeneral

DOCFILES=	Contents *.pdf *.eps *.ps *.dvi

PLIST_SUB=	HEAPSUBDIR=${ML_SYSTEM}_x86-bsd

.if defined(WITH_SMLNJ)
BUILD_DEPENDS+=	sml:${PORTSDIR}/lang/sml-nj-devel
RUN_DEPENDS+=	sml:${PORTSDIR}/lang/sml-nj-devel
.else
BUILD_DEPENDS+=	poly:${PORTSDIR}/lang/polyml
RUN_DEPENDS+=	poly:${PORTSDIR}/lang/polyml
.endif

NO_INSTALL_MANPAGES=yes

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@${CP} ${FILESDIR}/polyml-4.1.4-patch.ML ${WRKSRC}/src/Pure/ML-Systems/
	@${CP} ${FILESDIR}/polyml-4.2.0.ML ${WRKSRC}/src/Pure/ML-Systems/

post-patch:
	@${MV} ${WRKSRC}/etc/settings ${WRKSRC}/etc/settings.presed
	@${SED} "s|%%ML_SYSTEM%%|${ML_SYSTEM}|;		\
		 s|%%ML_HOME%%|${ML_HOME}|;		\
		 s|%%ML_OPTIONS%%|\"${ML_OPTIONS}\"|;	\
		 s|%%ML_DBASE%%|${ML_DBASE}|;		\
		 s|%%PREFIX%%|${PREFIX}|"		\
		${WRKSRC}/etc/settings.presed > ${WRKSRC}/etc/settings
	@${RM} ${WRKSRC}/etc/settings.presed
	@${TOUCH} ${WRKSRC}/contrib/.keep

pre-build:
.if !defined(WITH_SMLNJ)
	@if ${TEST} `ulimit -Hd` -lt 917504; then	\
		${CAT} ${FILESDIR}/badmaxdsiz;		\
		exit 1;					\
	fi
.endif

post-install:
	${WRKSRC}/bin/isatool ${INSTALL} -d ${PREFIX}/share/isabelle -p ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
	(cd ${WRKSRC}; \
	 ${FIND} -d browser_info -type d -exec ${MKDIR} ${DOCSDIR}/{} \; ; \
	 ${FIND} -d browser_info -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;)
.endif

.include <bsd.port.post.mk>
