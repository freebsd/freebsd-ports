PORTNAME=	fspclient
PORTVERSION=	0.93.1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Ftp-like client for the FSP service
WWW=		http://fspclient.sourceforge.net/

CONFLICTS_INSTALL=	alliance
USES=		tar:bzip2 scons
MAKE_ARGS=	prefix=${PREFIX}
CFLAGS+=	-Wno-incompatible-pointer-types-discards-qualifiers \
		-Wno-shadow \
		-Wno-incompatible-function-pointer-types

PLIST_FILES=	bin/fsp share/man/man1/fsp.1.gz
INSTALL_TARGET=	install prefix=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
