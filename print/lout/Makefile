# New ports collection makefile for: lout
# Date created:      10/22/96
# Whom:              oly@world.std.com
#
# $FreeBSD$
#

PORTNAME=	lout
PORTVERSION=	3.28
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN} \
		ftp://ftp.it.usyd.edu.au/jeff/lout/
MASTER_SITE_SUBDIR=	support/lout

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX like document creation system with PostScript/PDF output

USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=	lout prg2lout
INSTALL_TARGET=	install installman

.if !defined(NOPORTDOCS)
INSTALL_TARGET+=installdoc
.endif

MAN1=		prg2lout.1 lout.1

.include <bsd.port.mk>
