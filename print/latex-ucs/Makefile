# New ports collection makefile for:	latex-ucs
# Date created:		23 May 2004
# Whom:			thierry@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-ucs
PORTVERSION=	20041017
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://www.unruh.de/DniQ/latex/unicode/
DISTNAME=	unicode
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package for using UTF-8 as input encoding

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		${TEXMFDIR_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${TEXMFDIR_LSR}:${PORTSDIR}/print/tex-texmflocal

NO_BUILD=	yes
USE_PERL5_RUN=	yes
PLIST_SUB=	MKTEXLSR="${MKTEXLSR}" CLASSDIR=${CLASSDIR}

TEXMFDIR=	share/texmf
TEXMFDIR_LSR=	${LOCALBASE}/${TEXMFDIR}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr ${PREFIX}/${TEXMFDIR}
CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASS_FILES=	ucs.sty utf8x.def ucsencs.def ucsutils.sty ucshyper.sty
PLSCRIPTS=	discovermacro.pl latexout.pl makeunidef.pl
PORTDOCS=	FAQ INSTALL LICENSE README VERSION
CONTRIB_FILES= UnicodeT.sfd autofe.sty c00enc.def c10enc.def		\
	c40enc.def c42enc.def c61enc.def cenccmn.tex cp1252.enc		\
	ldvarial.fd ldvc2000.fd ldvenc.def letc2000.fd letenc.def	\
	letgfzem.fd letjiret.fd lklenc.def lklkli.fd ltaarial.fd	\
	ltac2000.fd ltaenc.def ltgc2000.fd ltgenc.def ltlcmr.fd		\
	ltlenc.def ltwdsnol.fd ltwdsque.fd ltwdssin.fd ltwenc.def	\
	lucarial.fd lucc2000.fd lucenc.def mkrenc.def mkrezra.fd	\
	mkrhadas.fd mkromega.fd mkrrashi.fd t2dcmr.fd t2denc.def	\
	tengwarDS.enc xscmr.fd xsenc.def

do-install:
	${INSTALL_SCRIPT} ${PLSCRIPTS:S@^@${WRKSRC}/@} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} \
		${CLASS_FILES:S@^@${WRKSRC}/@} \
		${CONTRIB_FILES:S@^@${WRKSRC}/contrib/@} \
		${PREFIX}/${CLASSDIR}
	${CP} -R ${WRKSRC}/data ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}

.include <bsd.port.mk>
