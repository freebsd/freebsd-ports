# New ports collection makefile for:	tmda
# Date created:				08 June 2001
# Whom:					Jason R. Mastaler <jason@mastaler.com>
#
# $FreeBSD$
#

PORTNAME=	tmda
PORTVERSION=	1.0.3
CATEGORIES=	mail python
MASTER_SITES=	http://www.tmda.net/releases/%SUBDIR%/ \
		http://www.us.tmda.net/releases/%SUBDIR%/ \
		http://tmda.mirrors.summersault.com/releases/%SUBDIR%/ \
		http://mirrors.standblue.net/tmda.net/releases/%SUBDIR%/ \
		http://www.de.tmda.net/releases/%SUBDIR%/ \
		http://www.pl.tmda.net/releases/%SUBDIR%/ \
		http://www.au.tmda.net/releases/%SUBDIR%/
MASTER_SITE_SUBDIR=	stable
EXTRACT_SUFX=	.tgz

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Python-based SPAM reduction system

.if defined(WITH_CDB)
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cdbmodule.so:${PORTSDIR}/databases/py-cdb
.endif

USE_PYTHON=	2.1+

PKGMESSAGE=	${WRKDIR}/pkg-message

DOCS=		CODENAMES CRYPTO README THANKS UPGRADE htdocs/*.html
DOCS2=		htdocs/img/*.png
SAMPLES=	sample.config tmda.el tofmipd.sysconfig vtmdarc
SCRIPTS=	collectaddys def2html printcdb printdbm sendit.sh \
	 	smtp-check-sender tofmipd.init tofmipd.sysconfig \
		update-internaldomains vadduser-tmda vmailmgr-vdir.sh \
		vpopmail-vdir.sh wrapfd3.sh

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} ./compileall

do-install:
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/TMDA/pythonlib/email
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/*.py* ${PYTHONPREFIX_SITELIBDIR}/TMDA
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/pythonlib/email/*.py* \
		${PYTHONPREFIX_SITELIBDIR}/TMDA/pythonlib/email
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/templates/*.txt ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/tmda-* ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/contrib && ${INSTALL_DATA} ${SAMPLES} ${EXAMPLESDIR}
	cd ${WRKSRC}/contrib && ${INSTALL_SCRIPT} ${SCRIPTS} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/img
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${DOCS} ${DOCSDIR} && \
		${INSTALL_DATA} ${DOCS2} ${DOCSDIR}/img
.endif
	@${SED} -e 's!PREFIX!${PREFIX}!; s!DOCSDIR!${DOCSDIR}!;' \
	       -e 's!EXAMPLESDIR!${EXAMPLESDIR}!' ${.CURDIR}/pkg-message \
	       > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
