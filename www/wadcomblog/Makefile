# New ports collection makefile for:	wadcomblog
# Date created:		2008-10-09
# Whom:			Julien Laffaye <kimelto@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	WadcomBlog
PORTVERSION=	0.3
CATEGORIES=	www python
MASTER_SITES=	http://laffaye.free.fr/distfiles/ \
		http://vss.73rus.com/wadcomblog/files/

MAINTAINER=	kimelto@gmail.com
COMMENT=	Simple open-source static blog engine written in Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.if !defined(NOPORTEXAMPLES)
	@${ECHO_MSG} "installing additional examples to ${EXAMPLESDIR}"
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/sample/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
