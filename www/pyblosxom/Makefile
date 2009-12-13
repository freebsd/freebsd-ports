# New ports collection makefile for:	pyblosxom
# Date created:		13 April 2005
# Whom:	      		Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	pyblosxom
PORTVERSION=	1.4.3
CATEGORIES=	www python
MASTER_SITES=	SF \
		http://dryice.name/computer/FreeBSD/distfiles/


MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	A lightweight weblog system

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}-${PORTVERSION}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docfile in INSTALL LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
