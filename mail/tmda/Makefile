# New ports collection makefile for:	tmda
# Date created:				08 June 2001
# Whom:					Jason R. Mastaler <jason@mastaler.com>
#
# $FreeBSD$
#

PORTNAME=	tmda
PORTVERSION=	0.44
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tmda
EXTRACT_SUFX=	.tgz

MAINTAINER=	jason@mastaler.com

USE_PYTHON=	yes

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
	${MKDIR} ${PREFIX}/share/doc/tmda/contrib
	${MKDIR} ${PREFIX}/share/doc/tmda/htdocs
.for f in ChangeLog COPYRIGHT CRYPTO INSTALL README THANKS UPGRADE
	@${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/tmda
.endfor
	@${INSTALL_DATA} ${WRKSRC}/contrib/* ${PREFIX}/share/doc/tmda/contrib
	@${INSTALL_DATA} ${WRKSRC}/htdocs/*.html ${PREFIX}/share/doc/tmda/htdocs
	@${ECHO_MSG}
	@${ECHO_MSG} See ${PREFIX}/share/doc/tmda/INSTALL for configuration instructions
	@${ECHO_MSG} See ${PREFIX}/share/doc/tmda/UPGRADE if upgrading from a previous release
.endif
	@${ECHO_MSG} All related programs have been installed in ${PREFIX}/bin
	@${ECHO_MSG}

.include <bsd.port.mk>
