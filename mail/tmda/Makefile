# New ports collection makefile for:	tmda
# Date created:				08 June 2001
# Whom:					Jason R. Mastaler <jason@mastaler.com>
#
# $FreeBSD$
#

PORTNAME=	tmda
PORTVERSION=	0.71
CATEGORIES=	mail python
MASTER_SITES=	http://tmda.net/releases/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
EXTRACT_SUFX=	.tgz

MAINTAINER=	mwm@mired.org
COMMENT=	Python-based SPAM reduction system

USE_PYTHON=	yes

do-build:
	(cd ${WRKSRC}; ${PYTHON_CMD} ./compileall)

pre-install:
	@${SH} ${PKGREQ} INSTALL

do-install:
	${MKDIR} ${PYTHON_SITELIBDIR}/TMDA/pythonlib/email
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/*.py* ${PYTHON_SITELIBDIR}/TMDA
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/pythonlib/email/*.py* \
		${PYTHON_SITELIBDIR}/TMDA/pythonlib/email
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/templates/*.txt ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/tmda-* ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/contrib ${DOCSDIR}/htdocs
.for f in CODENAMES COPYING CRYPTO ChangeLog INSTALL README THANKS UPGRADE
	@${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.for f in ChangeLog collectaddys printcdb sample.config sendit.sh tmda.spec \
		def2html printdbm tmda.el vadduser-tmda
	@${INSTALL_DATA} ${WRKSRC}/contrib/$f ${DOCSDIR}/contrib
.endfor
	@${INSTALL_DATA} ${WRKSRC}/htdocs/*.html ${DOCSDIR}/htdocs
	@${MKDIR} ${DOCSDIR}/contrib/cgi
	@${INSTALL_SCRIPT} ${WRKSRC}/contrib/cgi/*.py* ${DOCSDIR}/contrib/cgi
.for f in compile README tmda-cgi.conf tmda-cgi.c
	@${INSTALL_DATA} ${WRKSRC}/contrib/cgi/$f ${DOCSDIR}/contrib/cgi
.endfor
	@${MKDIR} ${DOCSDIR}/contrib/cgi/display
	@${INSTALL_DATA} ${WRKSRC}/contrib/cgi/display/* ${DOCSDIR}/contrib/cgi/display
	@${ECHO_MSG}
	@${ECHO_MSG} See ${DOCSDIR}/INSTALL for configuration instructions
	@${ECHO_MSG} See ${DOCSDIR}/UPGRADE if upgrading from a previous release
.endif
	@${ECHO_MSG} All related programs have been installed in ${PREFIX}/bin
	@${ECHO_MSG}

.include <bsd.port.mk>
