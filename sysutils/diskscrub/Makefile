PORTNAME=	diskscrub
PORTVERSION=	2.6.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/chaos/scrub/releases/download/${PORTVERSION}/
DISTNAME=	scrub-${PORTVERSION}

MAINTAINER=	erik@elfga.com
COMMENT=	Writes patterns on files to make retrieving the data more difficult
WWW=		https://code.google.com/p/diskscrub/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/scrub share/man/man1/scrub.1.gz

.include <bsd.port.mk>
