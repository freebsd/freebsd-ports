# New ports collection makefile for:	latex-ucs
# Date created:		23 May 2004
# Whom:			thierry@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-ucs
PORTVERSION=	20041017
PORTREVISION=	0
CATEGORIES=	print
MASTER_SITES=	http://www.unruh.de/DniQ/latex/unicode/
DISTNAME=	unicode
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package for using UTF-8 as input encoding

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal

NO_BUILD=	yes
USE_PERL5_RUN=	yes

PLIST_SUB=	MKTEXLSR=${MKTEXLSR} CLASSDIR=${CLASSDIR}
.if !defined(WITHOUT_CJK)
PLIST_SUB+=	CJK=""
.else
PLIST_SUB+=	CJK="@comment "
.endif

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASS_FILES=	ucs.sty utf8x.def ucsencs.def ucsutils.sty ucshyper.sty
CJK_FILES=	c00enc.def c10enc.def c40enc.def c42enc.def c61enc.def
PLSCRIPTS=	discovermacro.pl latexout.pl makeunidef.pl
PORTDOCS=	FAQ INSTALL LICENSE README VERSION

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you don't need CJK characters, please define WITHOUT_CJK."
	@${ECHO_MSG} ""

do-install:
	${INSTALL_SCRIPT} ${PLSCRIPTS:S@^@${WRKSRC}/@} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(WITHOUT_CJK)
	${INSTALL_DATA} ${CJK_FILES:S@^@${WRKSRC}/contrib/@} ${PREFIX}/${CLASSDIR}
.endif
	${CP} -R ${WRKSRC}/data ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
