# New ports collection makefile for:   rubber
# Date created:        25 march 2003
# Whom:                sbaro
#
# $FreeBSD$
#

PORTNAME=	rubber
PORTVERSION=	0.99.5
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.beffara.org/pub/ \
		http://www.beffara.org/pub/old/

MAINTAINER=	baro@pps.jussieu.fr
COMMENT=	Compilation of LaTeX files

USE_PYTHON=	yes

MAN1=		rubber.1 rubber-info.1
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=yes

.include <bsd.port.mk>
