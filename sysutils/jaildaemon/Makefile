PORTNAME=	jaildaemon
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://erdgeist.org/arts/software/jaildaemon/

MAINTAINER=	erdgeist@erdgeist.org
COMMENT=	Fixed command-line interface for FreeBSD jails to their host system
WWW=		https://erdgeist.org/arts/software/jaildaemon/

LICENSE=	BEERWARE
LICENSE_NAME=	beerware
LICENSE_TEXT=	See http://erdgeist.org/beerware.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tar:bzip2

PLIST_FILES=	bin/jaildaemon \
		etc/rc.d/jaildaemon \
		share/man/man1/jaildaemon.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|man/man|share/man/man|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
