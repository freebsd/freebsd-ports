# Created by: ijliao
# $FreeBSD$

PORTNAME=	latex-mk
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	misc print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Collection of makefile and scripts for LaTeX documents

LICENSE=	BSD4CLAUSE

BUILD_DEPENDS=	texi2dvi:${PORTSDIR}/print/texinfo
RUN_DEPENDS=	texi2dvi:${PORTSDIR}/print/texinfo

USE_TEX=	latex
USES=		gmake
GNU_CONFIGURE=	yes

INFO=		latex-mk

.include <bsd.port.mk>
