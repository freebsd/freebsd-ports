# New ports collection makefile for:	py-pygments
# Date created:		2007-04-01
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pygments
PORTVERSION=	1.1
PORTREVISION=	0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pygments-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A syntax highlighter written in Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Pygments

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
FIND_DOCS=	. -type f
MAN1=	pygmentize.1
MANCOMPRESSED=	no

post-install:
	@${INSTALL_DATA} ${WRKSRC}/docs/${MAN1} ${MANPREFIX}/man/man1/
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs/build && ${FIND} ${FIND_DOCS} -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} ";"
.endif

.include <bsd.port.mk>
