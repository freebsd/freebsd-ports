# ex:ts=8
# Ports collection Makefile for:	rubber
# Date created:			Mar 27, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rubber
PORTVERSION=	0.99.6
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://ebeffara.free.fr/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A wrapper for LaTeX and friends

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

USE_PYTHON=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --moddir=${PYTHON_SITELIBDIR}
USE_GMAKE=	yes

MANLANG=	"" fr
MAN1=	rubber.1 rubber-info.1

.include <bsd.port.mk>
