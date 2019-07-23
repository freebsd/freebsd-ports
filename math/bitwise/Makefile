# $FreeBSD$

PORTNAME=	bitwise
DISTVERSIONPREFIX=	v
DISTVERSION=	0.33
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal-based bit manipulator in curses

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf localbase ncurses readline
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	mellowcandle

PLIST_FILES=	bin/bitwise \
		man/man1/bitwise.1.gz

.include <bsd.port.mk>
