# ex:ts=8
# Ports collection makefile for:	guis
# Date created:			Apr 13, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	guis
PORTVERSION=	1.4
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.starynkevitch.net/Basile/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GUI widget server

USE_PYTHON=	2.3
USE_RUBY=	yes
USE_GNOME=	pkgconfig gtk20 pango libglade2 pygtk2
USE_GMAKE=	yes
MAKEFILE=	Makefile_guis
MAKE_ENV=	PYTHONCFLAGS="-I${LOCALBASE}/include/python${USE_PYTHON}" \
		PYTHONLDFLAGS="-L${LOCALBASE}/lib -lpython${USE_PYTHON}" \
		RUBY="ruby18"
ALL_TARGET=	prog

PLIST_FILES=	bin/pyguis bin/ruguis bin/pyguis-scripter bin/ruguis-scripter
MAN1=	pyguis.1
MLINKS=	pyguis.1 ruguis.1 \
	pyguis.1 pyguis-scripter.1 \
	pyguis.1 ruguis-scripter.1

do-install:
.for lang in py ru
	${INSTALL_PROGRAM} ${WRKSRC}/${lang}guis ${PREFIX}/bin
	${LN} -fs ${PREFIX}/bin/${lang}guis ${PREFIX}/bin/${lang}guis-scripter
.endfor
	${INSTALL_MAN} ${WRKSRC}/pyguis.man ${MAN1PREFIX}/man/man1/pyguis.1

.include <bsd.port.mk>
