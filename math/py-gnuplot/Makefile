# New ports collection makefile for:	py-gnuplot
# Date created:				3 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-gnuplot
PORTVERSION=	1.7
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnuplot-py
DISTNAME=	gnuplot-py-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to gnuplot plotting program

BUILD_DEPENDS=	${PYNUMERIC}
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		${PYNUMERIC}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/py-gnuplot
	cd ${WRKSRC}/doc && ${TAR} -chf - * | \
		${TAR} --unlink -xf - -C ${PREFIX}/share/doc/py-gnuplot
.endif

.include <bsd.port.mk>
