# New ports collection makefile for:	tmda
# Date created:				08 June 2001
# Whom:					Jason R. Mastaler <jason@mastaler.com>
#
# $FreeBSD$
#

PORTNAME=	tmda
PORTVERSION=	1.1.12
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	ftp://tmda.net/pub/tmda/releases/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sergei
EXTRACT_SUFX=	.tgz

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Python-based SPAM reduction system

.if defined(WITH_CDB)
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cdbmodule.so:${PORTSDIR}/databases/py-cdb
.endif

USE_PYTHON=	2.5+

SUB_FILES=	pkg-message

DOCS=		CODENAMES CRYPTO README THANKS NEWS UPGRADE
SAMPLES=	tmda.el tofmipd.sysconfig vtmdarc
SCRIPTS=	collectaddys def2html printcdb printdbm sendit.sh \
	 	smtp-check-sender tofmipd.init tofmipd.sysconfig \
		update-internaldomains vadduser-tmda vmailmgr-vdir.sh \
		vpopmail-vdir.sh wrapfd3.sh

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} ./compileall

do-install:
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/TMDA/pythonlib/email
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/TMDA/pythonlib/email/mime
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/TMDA/Queue
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/*.py* ${PYTHONPREFIX_SITELIBDIR}/TMDA
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/pythonlib/email/*.py* \
		${PYTHONPREFIX_SITELIBDIR}/TMDA/pythonlib/email
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/pythonlib/email/mime/*.py* \
		${PYTHONPREFIX_SITELIBDIR}/TMDA/pythonlib/email/mime
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/Queue/*.py* \
		${PYTHONPREFIX_SITELIBDIR}/TMDA/Queue
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/templates/*.txt ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/tmda-* ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}/dot-tmda/filters ${EXAMPLESDIR}/dot-tmda/lists
	cd ${WRKSRC}/contrib && \
		${INSTALL_SCRIPT} ${SCRIPTS} ${EXAMPLESDIR} && \
		${INSTALL_DATA} ${SAMPLES} ${EXAMPLESDIR}
	cd ${WRKSRC}/contrib/dot-tmda && \
		${INSTALL_DATA} [Rc]* ${EXAMPLESDIR}/dot-tmda && \
		${INSTALL_DATA} filters/* ${EXAMPLESDIR}/dot-tmda/filters && \
		${INSTALL_DATA} lists/* ${EXAMPLESDIR}/dot-tmda/lists
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${DOCSDIR}/html ${DOCSDIR}/pdf
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR} && \
		${CP} -r doc/html doc/pdf ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
