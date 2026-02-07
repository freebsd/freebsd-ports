PORTNAME=	minimunin
DISTVERSION=	0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://erdgeist.org/arts/software/minimunin/

MAINTAINER=	erdgeist@erdgeist.org
COMMENT=	Tiny munin-node implementation written in pure bourne shell
WWW=		https://erdgeist.org/arts/software/minimunin/

LICENSE=	Beerware
LICENSE_NAME=	Beerware License
LICENSE_TEXT=	The code is released under the beer ware license, this means do whatever you want with it, as long as you leave this notice along with the code.  Should we meet some day and you find the code is worth it, let's enjoy a beer together.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=	tar:bzip2

PLIST_FILES=	bin/minimunin
SUB_FILES=	pkg-message

NO_ARCH=yes
NO_BUILD=yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/minimunin ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
