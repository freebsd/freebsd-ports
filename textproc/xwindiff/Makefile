# $FreeBSD$

PORTNAME=	xwindiff
PORTVERSION=	1.1.6
CATEGORIES=	textproc
MASTER_SITES=	http://www.lurklurk.org/downloads/
DIST_SUBDIR=	repacked

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical Diff for X

USES=		xorg
USE_XORG=	x11 xt ice xaw
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${STAGEDIR}${PREFIX}/bin
PLIST_FILES=	bin/xwindiff

pre-configure:
	${REINPLACE_CMD} -e 's|^bindir = .*|bindir = @bindir@|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
