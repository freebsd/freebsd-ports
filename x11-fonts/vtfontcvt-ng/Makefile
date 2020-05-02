# $FreeBSD$

PORTNAME=	vtfontcvt-ng
DISTVERSION=	g20190823
CATEGORIES=	x11-fonts

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Improved version of vtfontcvt(8)

LICENSE=	BSD2CLAUSE

USES=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	t6
GH_TAGNAME=	29c4d75085c606b3f96f611bd64de537070e8b6d

MAKE_ARGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man
PLIST_FILES=	bin/vtfontcvt-ng \
		man/man8/vtfontcvt-ng.8.gz

.include <bsd.port.mk>
