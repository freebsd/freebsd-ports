# Created by: rom
# $FreeBSD$

PORTNAME=	geg
PORTVERSION=	1.0.2
PORTREVISION=	8
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.infolaunch.com/~daveb/
MASTER_SITE_SUBDIR=	science/visualization/plotting

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visualise multiple 2D-functions of one variable

USE_GNOME=	gtk12
USE_AUTOTOOLS=	automake autoconf
AUTOMAKE_ARGS=	-a -i
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PLIST_FILES=	bin/geg \
		man/man1/geg.1.gz

pre-configure:
	@(cd ${WRKSRC}; ${ACLOCAL} -I ${LOCALBASE}/share/aclocal)

.include <bsd.port.mk>
