# New ports collection makefile for:	tex-texmflocal
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	tex-texmflocal
PORTVERSION=	1.0
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Meta-port that creates a site-local $$TEXMF directory

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL} MKTEXLSR=${MKTEXLSR}
PKGINSTALL=	${WRKDIR}/pkg-install.sh
PKGDEINSTALL=	${WRKDIR}/pkg-install.sh

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

DIRS=	bibtex bibtex/bib bibtex/bst
DIRS+=	dvipdfm dvips
DIRS+=	fonts fonts/afm fonts/ofm fonts/ovp fonts/ovf
DIRS+=	fonts/ocp fonts/pk fonts/tfm fonts/type1
DIRS+=	fonts/source fonts/source/public fonts/vf
DIRS+=	jbibtex jbibtex/bib jbibtex/bst
DIRS+=	tex tex/generic tex/jadetex tex/latex tex/plain
DIRS+=	pdftex pdftex/latex pdftex/platex
DIRS+=	ptex ptex/plain ptex/platex

do-install:
	${MKDIR} ${DIRS:S,^,${PREFIX}/${TEXMFLOCAL}/,}
	${SED} -e 's,%%TEXMFLOCAL_LSR%%,${TEXMFLOCAL_LSR},' \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	${CHMOD} 0555 ${PKGINSTALL}

post-install:
	@${MKTEXLSR}
	@${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
