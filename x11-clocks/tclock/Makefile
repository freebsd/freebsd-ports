PORTNAME=	tclock
DISTVERSION=	1.0.1
PORTREVISION=	5
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.linta.de/distfiles/ \
		http://www.gnu-darwin.org/distfiles/

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Transparent analog clock for x11

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		imake tar:Z xorg
USE_XORG=	x11 xext xorgproto

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/tclock share/man/man1/tclock.1.gz

.include <bsd.port.mk>
