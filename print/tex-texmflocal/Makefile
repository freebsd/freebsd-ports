# New ports collection makefile for:	tex-texmflocal
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	tex-texmflocal
PORTVERSION=	1.7
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Meta-port that creates a site-local $$TEXMF directory

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install.sh
PKGDEINSTALL=	${WRKDIR}/pkg-install.sh
PLIST=		${WRKDIR}/pkg-plist

TEXMF=		share/texmf
TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
TEXMFVAR=	share/texmf-var
TEXMFVAR_LSR=	${LOCALBASE}/${TEXMFVAR}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

DIRS=	bibtex/bib bibtex/bst bibtex\
	context/config context \
	doc/latex doc \
	dvipdfm/config dvipdfm dvips/config dvips \
	etex/plain/config etex/plain etex \
	fonts/afm fonts/ofm fonts/ovp fonts/ovf \
	fonts/ocp fonts/pk fonts/tfm fonts/type1 \
	fonts/source/public fonts/source fonts/vf fonts \
	makeindex metafont metapost \
	jbibtex/bib jbibtex/bst jbibtex\
	tex/generic/config tex/generic \
	tex/jadetex tex/latex/base tex/latex tex/plain tex\
	pdftex/config pdftex/latex pdftex/platex pdftex\
	ptex/plain ptex/platex ptex\
	web2c xdvi

LSRMAGIC=${ECHO_CMD} "% ls-R -- filename database for kpathsea; do not change this line."

pre-install:
	(${ECHO_CMD} "bin/tetex-modesw"; \
	for dir in ${DIRS}; do \
		${ECHO_CMD} "@unexec ${RMDIR} %D/${TEXMFLOCAL}/$${dir} > /dev/null 2>&1 || true"; \
		${ECHO_CMD} "@unexec ${RMDIR} %D/${TEXMFVAR}/$${dir} > /dev/null 2>&1 || true"; \
		${ECHO_CMD} "@exec ${MKDIR} %D/${TEXMFLOCAL}/$${dir}"; \
		${ECHO_CMD} "@exec ${MKDIR} %D/${TEXMFVAR}/$${dir}"; \
	done; \
	${ECHO_CMD} '@exec ${LSRMAGIC:S,%,%%,g} > ${TEXMFLOCAL_LSR} && ${CHMOD} 0644 ${TEXMFLOCAL_LSR}'; \
	${ECHO_CMD} '@exec ${LSRMAGIC:S,%,%%,g} > ${TEXMFVAR_LSR} && ${CHMOD} 0644 ${TEXMFVAR_LSR}'; \
	${ECHO_CMD} '@unexec ${RM} -f ${TEXMFLOCAL_LSR} > /dev/null 2>&1 || true'; \
	${ECHO_CMD} '@unexec ${RM} -f ${TEXMFVAR_LSR} > /dev/null 2>&1 || true'; \
	${ECHO_CMD} "@unexec ${RMDIR} %D/${TEXMFLOCAL} > /dev/null 2>&1 || true"; \
	${ECHO_CMD} "@unexec ${RMDIR} %D/${TEXMFVAR} > /dev/null 2>&1 || true"; \
	${ECHO_CMD} '@exec if [ -x ${MKTEXLSR} ]; then ${MKTEXLSR}; fi'; \
	${ECHO_CMD} '@unexec if [ -x ${MKTEXLSR} ]; then ${MKTEXLSR}; fi'; \
	) > ${PLIST}

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/tetex-modesw.in ${PREFIX}/bin/tetex-modesw
	${MKDIR} ${DIRS:S,^,${PREFIX}/${TEXMFLOCAL}/,}
	${MKDIR} ${DIRS:S,^,${PREFIX}/${TEXMFVAR}/,}
	${LSRMAGIC} > ${TEXMFLOCAL_LSR}
	${CHMOD} 0644 ${TEXMFLOCAL_LSR}
	${LSRMAGIC} > ${TEXMFVAR_LSR}
	${CHMOD} 0644 ${TEXMFVAR_LSR}

post-install:
	@if [ -x ${MKTEXLSR} ]; then ${MKTEXLSR}; fi

.include <bsd.port.mk>
