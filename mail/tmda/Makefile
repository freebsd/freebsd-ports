# Created by: Jason R. Mastaler <jason@mastaler.com>
# $FreeBSD$

PORTNAME=	tmda
PORTVERSION=	1.1.12
PORTREVISION=	2
CATEGORIES=	mail python
MASTER_SITES=	ftp://tmda.net/pub/tmda/releases/ \
		LOCAL/sergei

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python-based SPAM reduction system

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python shebangfix tar:tgz
SHEBANG_FILES=	contrib/tofmipd.init
SUB_FILES=	pkg-message
NO_ARCH=	yes

DOCS=		CODENAMES CRYPTO README THANKS NEWS UPGRADE
SAMPLES=	tmda.el tofmipd.sysconfig vtmdarc
SCRIPTS=	collectaddys def2html printcdb printdbm sendit.sh \
		smtp-check-sender tofmipd.init tofmipd.sysconfig \
		update-internaldomains vadduser-tmda vmailmgr-vdir.sh \
		vpopmail-vdir.sh wrapfd3.sh

OPTIONS_DEFINE=	CDB DOCS EXAMPLES
CDB_RUN_DEPENDS=${PYTHON_SITELIBDIR}/cdbmodule.so:databases/py-cdb

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} ./compileall

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/TMDA/pythonlib/email
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/TMDA/pythonlib/email/mime
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/TMDA/Queue
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/*.py* ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/TMDA
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/pythonlib/email/*.py* \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/TMDA/pythonlib/email
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/pythonlib/email/mime/*.py* \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/TMDA/pythonlib/email/mime
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/Queue/*.py* \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/TMDA/Queue
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/templates/*.txt ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/tmda-* ${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/dot-tmda/filters ${STAGEDIR}${EXAMPLESDIR}/dot-tmda/lists
	cd ${WRKSRC}/contrib && \
		${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${EXAMPLESDIR} && \
		${INSTALL_DATA} ${SAMPLES} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/contrib/dot-tmda && \
		${INSTALL_DATA} [Rc]* ${STAGEDIR}${EXAMPLESDIR}/dot-tmda && \
		${INSTALL_DATA} filters/* ${STAGEDIR}${EXAMPLESDIR}/dot-tmda/filters && \
		${INSTALL_DATA} lists/* ${STAGEDIR}${EXAMPLESDIR}/dot-tmda/lists

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR}/html ${STAGEDIR}${DOCSDIR}/pdf
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR} && \
		${CP} -r doc/html doc/pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
