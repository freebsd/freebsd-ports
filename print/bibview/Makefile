# New ports collection makefile for:	bibview
# Date created:		21 July 1997
# Whom:			dbader@eece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	bibview
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	print databases
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR= biblio/bibtex/utils/bibview-2.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical interface for manipulating BibTeX bibliography databases

USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xt
WRKSRC=		${WRKDIR}/bibview-${PORTVERSION}
MAN1=		bibview.1

.include <bsd.port.mk>
