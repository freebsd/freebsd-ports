# ex:ts=8
# Ports collection Makefile for:	rubber
# Date created:			Mar 27, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rubber
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://ebeffara.free.fr/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A wrapper for LaTeX and friends

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

USE_PYTHON=	2.2+
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --infodir=${PREFIX}/${INFO_PATH} \
		--datadir=${PYTHON_SITELIBDIR}

MANLANG=	"" fr
MAN1=		rubber.1 rubber-info.1 rubber-pipe.1
INFO=		rubber

.include <bsd.port.mk>
