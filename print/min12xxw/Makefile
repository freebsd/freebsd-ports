PORTNAME=	min12xxw
PORTVERSION=	0.0.9
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://hinterbergen.de/mala/min12xxw/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print driver for the Minolta PagePro 1(2/3/4)xxW printers
WWW=		http://hinterbergen.de/mala/min12xxw/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/esc-m \
		bin/min12xxw \
		share/man/man1/min12xxw.1.gz

.include <bsd.port.mk>
