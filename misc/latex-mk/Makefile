# ex:ts=8
# Ports collection makefile for:	latex-mk
# Date created:			May 22, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	latex-mk
PORTVERSION=	1.9.1
PORTREVISION=	1
CATEGORIES=	misc print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	kimelto@gmail.com
COMMENT=	A collection of makefile and scripts for LaTeX documents

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

INFO=		latex-mk

.include <bsd.port.mk>
