# New ports collection makefile for:   rawdog
# Date created:        9 September 2003
# Whom:                Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	rawdog
PORTVERSION=	1.4
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
	@echo "    ---------------------------------------------"
	@echo "    Sample config and stylesheet installed in:"
	@echo "        ${EXAMPLESDIR}"
.if !defined(NOPORTDOCS)
	@echo "    Please read the README:"
	@echo "        ${DOCSDIR}/README"
.endif
	@echo "    ---------------------------------------------"

.include <bsd.port.mk>
