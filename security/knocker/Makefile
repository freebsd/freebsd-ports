PORTNAME=	knocker
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	SF

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Simple and easy to use TCP only port scanner (Console version)
WWW=		https://knocker.sourceforge.io

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/knocker \
		share/man/man1/knocker.1.gz

.include <bsd.port.mk>
