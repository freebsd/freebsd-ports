# $FreeBSD$

PORTNAME=	rw
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	https://sortix.org/rw/release/
DISTNAME=	rw-portable-${PORTVERSION}

MAINTAINER=	jsmith@resonatingmedia.com
COMMENT=	Simple replacement for dd wth standard command line flags

LICENSE=	ISCL

PLIST_FILES=	bin/rw man/man1/rw.1.gz

pre-patch:
	@${REINPLACE_CMD} -e 's|$$(PREFIX)/share|$$(PREFIX)|' \
	  	${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
