# New ports collection makefile for:	tex-texmflocal
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	tex-texmflocal
PORTVERSION=	1.3
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Meta-port that creates a site-local $$TEXMF directory

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install.sh
PKGDEINSTALL=	${WRKDIR}/pkg-install.sh
PLIST=		${WRKDIR}/pkg-plist

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

DIRS=	bibtex/bib bibtex/bst bibtex\
	dvipdfm dvips \
	fonts/afm fonts/ofm fonts/ovp fonts/ovf \
	fonts/ocp fonts/pk fonts/tfm fonts/type1 \
	fonts/source/public fonts/source fonts/vf fonts \
	metafont metapost \
	jbibtex/bib jbibtex/bst jbibtex\
	tex/generic tex/jadetex tex/latex tex/plain tex\
	pdftex/latex pdftex/platex pdftex\
	ptex/plain ptex/platex ptex\
	web2c

pre-install:
	(${ECHO_CMD} '${TEXMFLOCAL}/ls-R'; \
		for dir in ${DIRS}; do \
			${ECHO_CMD} "@dirrm ${TEXMFLOCAL}/$${dir}"; \
			${ECHO_CMD} "@exec ${MKDIR} %D/${TEXMFLOCAL}/$${dir}"; \
		done; \
		${ECHO_CMD} '@exec ${MKTEXLSR}'; \
		${ECHO_CMD} '@unexec ${MKTEXLSR}' ) > ${PLIST}
	${SED} -e 's,%%TEXMFLOCAL_LSR%%,${TEXMFLOCAL_LSR},' \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	${CHMOD} 0555 ${PKGINSTALL}

do-install:
	${MKDIR} ${DIRS:S,^,${PREFIX}/${TEXMFLOCAL}/,}

post-install:
	@${MKTEXLSR}
	@${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
