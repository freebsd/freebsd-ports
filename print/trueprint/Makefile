# Created by: Dmitry Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	trueprint
PORTVERSION=	5.4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	trueprint

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Print program listings on postscript printer

USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

MAN1=		trueprint.1
INFO=		trueprint

PLIST_FILES=	bin/trueprint

.include <bsd.port.mk>
