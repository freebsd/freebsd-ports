# New ports collection makefile for:   rawdog
# Date created:        9 September 2003
# Whom:                Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	rawdog
PORTVERSION=	1.13
CATEGORIES=	news python
MASTER_SITES=	http://offog.org/files/

MAINTAINER=	tim@bishnet.net
COMMENT=	A simple RSS aggregator

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/style.css ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${ECHO_MSG} "    ---------------------------------------------"
	@${ECHO_MSG} "    Sample config and stylesheet installed in:"
	@${ECHO_MSG} "        ${EXAMPLESDIR}"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "    Please read the README:"
	@${ECHO_MSG} "        ${DOCSDIR}/README"
.endif
	@${ECHO_MSG} "    ---------------------------------------------"

.include <bsd.port.mk>
