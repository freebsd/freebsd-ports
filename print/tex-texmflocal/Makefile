# New ports collection makefile for:	tex-texmflocal
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	tex-texmflocal
PORTVERSION=	1.9
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

TEXMFDIR=	share/texmf
TEXMF_LSR=	${PREFIX}/${TEXMFDIR}/ls-R
TEXMFLOCALDIR=	share/texmf-local
TEXMFLOCAL_LSR=	${PREFIX}/${TEXMFLOCALDIR}/ls-R
TEXMFVARDIR=	share/texmf-var
TEXMFVAR_LSR=	${PREFIX}/${TEXMFVARDIR}/ls-R
TEXMFCONFIGDIR=	share/texmf-config
TEXMFCONFIG_LSR=${PREFIX}/${TEXMFCONFIGDIR}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

.include <bsd.port.pre.mk>

DIRS!=		${CAT} ${FILESDIR}/dirlist

LSRMAGIC=( ${ECHO_CMD} "% ls-R -- filename database for kpathsea; do not change this line."; \
	${ECHO_CMD} "./:"; \
	${ECHO_CMD} "ls-R"; \
	${ECHO_CMD} ""; )

pre-install:
	(${ECHO_CMD} "bin/tetex-modesw"; \
	for dir in ${DIRS}; do \
		${ECHO_CMD} "@unexec ${RMDIR} %D/${TEXMFDIR}/$${dir} > /dev/null 2>&1 || true"; \
		${ECHO_CMD} "@unexec ${RMDIR} %D/${TEXMFLOCALDIR}/$${dir} > /dev/null 2>&1 || true"; \
		${ECHO_CMD} "@unexec ${RMDIR} %D/${TEXMFVARDIR}/$${dir} > /dev/null 2>&1 || true"; \
		${ECHO_CMD} "@unexec ${RMDIR} %D/${TEXMFCONFIGDIR}/$${dir} > /dev/null 2>&1 || true"; \
		${ECHO_CMD} "@exec ${MKDIR} %D/${TEXMFDIR}/$${dir}"; \
		${ECHO_CMD} "@exec ${MKDIR} %D/${TEXMFLOCALDIR}/$${dir}"; \
		${ECHO_CMD} "@exec ${MKDIR} %D/${TEXMFVARDIR}/$${dir}"; \
		${ECHO_CMD} "@exec ${MKDIR} %D/${TEXMFCONFIGDIR}/$${dir}"; \
	done; \
	${ECHO_CMD} '@exec ${LSRMAGIC:S,%,%%,g} > ${TEXMF_LSR} && ${CHMOD} 0644 ${TEXMF_LSR}'; \
	${ECHO_CMD} '@exec ${LSRMAGIC:S,%,%%,g} > ${TEXMFLOCAL_LSR} && ${CHMOD} 0644 ${TEXMFLOCAL_LSR}'; \
	${ECHO_CMD} '@exec ${LSRMAGIC:S,%,%%,g} > ${TEXMFVAR_LSR} && ${CHMOD} 0644 ${TEXMFVAR_LSR}'; \
	${ECHO_CMD} '@exec ${LSRMAGIC:S,%,%%,g} > ${TEXMFCONFIG_LSR} && ${CHMOD} 0644 ${TEXMFCONFIG_LSR}'; \
	${ECHO_CMD} '@unexec ${RM} -f ${TEXMF_LSR} > /dev/null 2>&1 || true'; \
	${ECHO_CMD} '@unexec ${RM} -f ${TEXMFLOCAL_LSR} > /dev/null 2>&1 || true'; \
	${ECHO_CMD} '@unexec ${RM} -f ${TEXMFVAR_LSR} > /dev/null 2>&1 || true'; \
	${ECHO_CMD} '@unexec ${RM} -f ${TEXMFCONFIG_LSR} > /dev/null 2>&1 || true'; \
	${ECHO_CMD} "@unexec ${RMDIR} %D/${TEXMFDIR} > /dev/null 2>&1 || true"; \
	${ECHO_CMD} "@unexec ${RMDIR} %D/${TEXMFLOCALDIR} > /dev/null 2>&1 || true"; \
	${ECHO_CMD} "@unexec ${RMDIR} %D/${TEXMFVARDIR} > /dev/null 2>&1 || true"; \
	${ECHO_CMD} "@unexec ${RMDIR} %D/${TEXMFCONFIGDIR} > /dev/null 2>&1 || true"; \
	${ECHO_CMD} '@exec if [ -x ${MKTEXLSR} ]; then ${MKTEXLSR}; fi'; \
	${ECHO_CMD} '@unexec if [ -x ${MKTEXLSR} ]; then ${MKTEXLSR}; fi'; \
	) > ${PLIST}

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/tetex-modesw.in ${PREFIX}/bin/tetex-modesw
.for D in TEXMF TEXMFLOCAL TEXMFVAR TEXMFCONFIG
	${MKDIR} ${DIRS:S,^,${PREFIX}/${${D}DIR}/,}
	${LSRMAGIC} > ${${D}_LSR}
	${CHMOD} 0644 ${${D}_LSR}
.endfor

post-install:
	@if [ -x ${MKTEXLSR} ]; then ${MKTEXLSR}; fi

.include <bsd.port.post.mk>
