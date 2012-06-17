# New ports collection makefile for: lout
# Date created:      10/22/96
# Whom:              oly@world.std.com
#
# $FreeBSD$
#

PORTNAME=	lout
PORTVERSION=	3.39
CATEGORIES=	print
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX like document creation system with PostScript/PDF output

LICENSE=	GPLv3 # (or later)

OPTIONS_DEFINE=	DOCS

USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=	lout prg2lout
MAKE_JOBS_SAFE=	yes

MAN1=		lout.1 prg2lout.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET=	install installman installdoc
.else
INSTALL_TARGET=	install installman
.endif

.include <bsd.port.mk>
