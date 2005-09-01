# New ports collection makefile for:   isabelle
# Date created:        08 August 2005
# Whom:                Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	isabelle
PORTVERSION=	2004
CATEGORIES=	math
MASTER_SITES=	http://isabelle.in.tum.de/dist/packages/ \
		http://www.cl.cam.ac.uk/Research/HVG/Isabelle/dist/packages/ \
		http://mirror.cse.unsw.edu.au/pub/isabelle/packages/
DISTNAME=	Isabelle2004
.if !defined(NOPORTDOCS)
DISTFILES=	Isabelle2004.tar.gz \
		Isabelle2004_library.tar.gz \
		Isabelle2004_pdf.tar.gz
.endif

MAINTAINER=	timbob@bigpond.com
COMMENT=	A generic proof assistant

.if defined(WITH_SMLNJ)
ML_COMMENT=	Standard ML of New Jersey 110 or later
ML_SYSTEM=	smlnj-110
ML_HOME=	${LOCALBASE}/lib/sml-nj/bin
ML_OPTIONS=	@SMLdebug=/dev/null
ML_DBASE=
.else
# Poly/ML 4.0, 4.1, 4.1.x
ML_COMMENT=	Poly/ML 4.0, 4.1, 4.1.x
ML_SYSTEM=	polyml-4.1.3
ML_HOME=	${LOCALBASE}/lib/polyml/
ML_OPTIONS=	-h 15000
ML_DBASE=	${LOCALBASE}/lib/polyml/ML_dbase
.endif

USE_PERL5=	yes
HAS_CONFIGURE=	yes
BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS+=	proofgeneral:${PORTSDIR}/math/proofgeneral

PORTDOCS=	Contents index.html *.pdf *.eps *.ps *.dvi

.if defined(WITH_SMLNJ)
BUILD_DEPENDS+=	sml:${PORTSDIR}/lang/sml-nj
RUN_DEPENDS+=	sml:${PORTSDIR}/lang/sml-nj
.else
BUILD_DEPENDS+=	poly:${PORTSDIR}/lang/polyml
RUN_DEPENDS+=	poly:${PORTSDIR}/lang/polyml
.endif

NO_INSTALL_MANPAGES=yes

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-patch:
	@${MV} ${WRKSRC}/etc/settings ${WRKSRC}/etc/settings.presed
	@${SED} "s|%%ML_COMMENT%%|${ML_COMMENT}|;	\
		 s|%%ML_SYSTEM%%|${ML_SYSTEM}|;		\
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
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
	(cd ${WRKSRC}; \
	 ${FIND} -d browser_info -type d -exec ${MKDIR} ${DOCSDIR}/{} \; ; \
	 ${FIND} -d browser_info -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;)
.endif

.include <bsd.port.mk>
