PORTNAME=	tclock
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.linta.de/distfiles/ \
		ftp://ftp.uni-potsdam.de/pub/X11/tools/clocks/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Transparent analog clock for x11

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		imake tar:Z xorg
USE_XORG=	x11 xext

PLIST_FILES=	bin/tclock share/man/man1/${PORTNAME}.1.gz
NO_WRKSUBDIR=	yes

.include <bsd.port.mk>
