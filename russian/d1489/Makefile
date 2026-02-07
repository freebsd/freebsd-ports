PORTNAME=	d1489
DISTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	russian converters
MASTER_SITES=	LOCAL/eugen \
		http://www.grosbein.net/freebsd/distfiles/

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Cp866<->koi8-r and cp1251<->koi8-r decoders, font converter (RFC1489)
WWW=		https://koi8.pp.ru/unix.html

# Mentioned in README and Makefile, but not in the source code.
LICENSE=	BSD2CLAUSE

USES=		tar:tgz

MAKE_ARGS=	PREFIX=${PREFIX} STAGEDIR=${STAGEDIR}

PLIST_FILES=	bin/a2kfcnv bin/fromdos bin/todos bin/fromwin bin/towin

.include <bsd.port.mk>
