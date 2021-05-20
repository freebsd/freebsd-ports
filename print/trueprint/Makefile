# Created by: Dmitry Sivachenko <dima@Chg.RU>

PORTNAME=	trueprint
PORTVERSION=	5.4
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	GNU

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Print program listings on postscript printer

USES=		gettext gmake
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

INFO=		trueprint

PLIST_FILES=	bin/trueprint man/man1/trueprint.1.gz

.include <bsd.port.mk>
