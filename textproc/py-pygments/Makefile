# New ports collection makefile for:	py-pygments
# Date created:		2007-04-01
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pygments
PORTVERSION=	1.4
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

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

MAN1=	pygmentize.1

post-install:
	@${INSTALL_MAN} ${WRKSRC}/docs/${MAN1} ${MANPREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs/build && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
