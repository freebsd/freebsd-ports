PORTNAME=	lout
PORTVERSION=	3.42
CATEGORIES=	print

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	LaTeX like document creation system with PostScript/PDF output

LICENSE=	GPLv3+

USES=		cpe gmake
CPE_VENDOR=	lout_project

USE_GITHUB=	yes
GH_ACCOUNT=	william8000

MAKEFILE=	makefile
ALL_TARGET=	lout prg2lout
INSTALL_TARGET=	install installman installdoc

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
