PORTNAME=	fparser
DISTVERSION=	4.5.2
CATEGORIES=	math
MASTER_SITES=	http://warp.povusers.org/FunctionParser/ # another fork exists: https://github.com/thliebig/fparser
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Function parser for C++

LICENSE=	LGPL3

USES=		autoreconf gmake libtool zip
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

NO_WRKSUBDIR=	yes

INSTALL_TARGET=	install-strip

PLIST_FILES=	include/fparser/fparser.hh \
		include/fparser/fpaux.hh \
		include/fparser/fpconfig.hh \
		include/fparser/fptypes.hh \
		lib/libfparser-4.5.so \
		lib/libfparser.so \
		libdata/pkgconfig/fparser.pc

.include <bsd.port.mk>
