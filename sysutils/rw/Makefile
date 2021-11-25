PORTNAME=	rw
DISTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://sortix.org/rw/release/
DISTNAME=	rw-portable-${DISTVERSION}

MAINTAINER=	jsmith@resonatingmedia.com
COMMENT=	Simple replacement for dd(1) with standard command-line flags

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	rankwidth

PLIST_FILES=	bin/rw share/man/man1/rw.1.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
