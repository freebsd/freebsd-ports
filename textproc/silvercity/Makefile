# ex:ts=8
# Ports collection makefile for:	silvercity
# Date created:			Dec 29, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	silvercity
PORTVERSION=	0.9.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	SilverCity-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lexing package for over 20 programming and markup langauges

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes

# convert scripts EOL from DOS to NIX
post-extract:
	@${REINPLACE_CMD} -e 's,$$,,' ${WRKSRC}/PySilverCity/Scripts/*.py

.include <bsd.port.mk>
