# New ports collection makefile for:	tex-texmflocal
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	tex-texmflocal
PORTVERSION=	1.2
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

DIRS=	bibtex bibtex/bib bibtex/bst \
	dvipdfm dvips \
	fonts fonts/afm fonts/ofm fonts/ovp fonts/ovf \
	fonts/ocp fonts/pk fonts/tfm fonts/type1 \
	fonts/source fonts/source/public fonts/vf \
	metafont metapost \
	jbibtex jbibtex/bib jbibtex/bst \
	tex tex/generic tex/jadetex tex/latex tex/plain \
	pdftex pdftex/latex pdftex/platex \
	ptex ptex/plain ptex/platex \
	web2c

do-install:
	${MKDIR} ${DIRS:S,^,${PREFIX}/${TEXMFLOCAL}/,}
	${SED} -e 's,%%TEXMFLOCAL_LSR%%,${TEXMFLOCAL_LSR},' \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	${CHMOD} 0555 ${PKGINSTALL}

post-install:
	@${MKTEXLSR}
	@${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
