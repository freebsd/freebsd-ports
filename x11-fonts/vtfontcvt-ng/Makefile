# $FreeBSD$

PORTNAME=	vtfontcvt-ng
DISTVERSION=	g20190119
CATEGORIES=	x11-fonts

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Improved version of vtfontcvt(8)

LICENSE=	BSD2CLAUSE

USES=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	t6
GH_TAGNAME=	fd00785a764f1c699f03d53e8a7ef308eb0b78f8

MAKE_ARGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man
PLIST_FILES=	bin/vtfontcvt-ng \
		man/man8/vtfontcvt-ng.8.gz

.include <bsd.port.mk>
