# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	wmwork
PORTVERSION=	0.2.5
PORTREVISION=	3
CATEGORIES=	misc windowmaker afterstep
MASTER_SITES=	http://people.debian.org/~godisch/wmwork/ \
		LOCAL/xride

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Dockapp that keeps track of time you have spent on something

BROKEN_FreeBSD_13=	duplicate symbol: display
BROKEN_FreeBSD_14=	duplicate symbol: display

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USES=		gmake xorg
USE_XORG=	xpm
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/wmwork man/man1/wmwork.1.gz

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmwork ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmwork.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
