# Created by: Lars Koeller <lkoeller@cc.fh-lippe.de>
# $FreeBSD$

PORTNAME=	tclock
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.linta.de/distfiles/ \
		ftp://ftp.uni-potsdam.de/pub/X11/tools/clocks/

MAINTAINER=	aehlig@linta.de
COMMENT=	Transparent analog clock for x11

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		imake tar:Z xorg
USE_XORG=	x11 xext

PLIST_FILES=	bin/tclock man/man1/${PORTNAME}.1.gz
NO_WRKSUBDIR=	yes

.include <bsd.port.mk>
