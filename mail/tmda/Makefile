# New ports collection makefile for:	tmda
# Date created:				08 June 2001
# Whom:					Jason R. Mastaler <jason@mastaler.com>
#
# $FreeBSD$
#

PORTNAME=	tmda
PORTVERSION=	0.37
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tmda
EXTRACT_SUFX=	.tgz

MAINTAINER=	jason@mastaler.com

RUN_DEPENDS=    ${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail

USE_PYTHON=	yes

.if exists(${PREFIX}/qmail/bin/qmail-send)
QMAIL_DIR?=     ${PREFIX}/qmail
.else
QMAIL_DIR?=     /var/qmail
.endif

do-build:
	(cd ${WRKSRC}; ${PYTHON_CMD} ./compileall)

do-install:
	${MKDIR} ${PYTHON_SITELIBDIR}/TMDA
	${INSTALL_SCRIPT} ${WRKSRC}/TMDA/*.py* ${PYTHON_SITELIBDIR}/TMDA
	${MKDIR} ${PREFIX}/share/tmda
	${INSTALL_DATA} ${WRKSRC}/templates/*.txt ${PREFIX}/share/tmda
	${INSTALL_SCRIPT} ${WRKSRC}/bin/tmda-* ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tmda
.for f in ChangeLog COPYRIGHT CRYPTO FAQ INSTALL README THANKS TODO UPGRADE contrib/*.* doc/tmda*
	@${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/tmda
.endfor
	@${ECHO_MSG}
	@${ECHO_MSG} See ${PREFIX}/share/doc/tmda/INSTALL for configuration instructions
.endif
	@${ECHO_MSG} All related programs have been installed in ${PREFIX}/bin
	@${ECHO_MSG}

.include <bsd.port.mk>
