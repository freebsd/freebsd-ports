# Created by: oly@world.std.com
# $FreeBSD$

PORTNAME=	lout
PORTVERSION=	3.40
CATEGORIES=	print
MASTER_SITES=	SAVANNAH

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	LaTeX like document creation system with PostScript/PDF output

LICENSE=	GPLv3 # (or later)

OPTIONS_DEFINE=	DOCS

USES=	gmake
MAKEFILE=	makefile
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}
ALL_TARGET=	lout prg2lout
INSTALL_TARGET=	install installman installdoc

.include <bsd.port.mk>
