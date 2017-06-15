# $FreeBSD$

PORTNAME=	oysttyer
PORTVERSION=	2.8.1
CATEGORIES=	net-im

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Interactive console text-based command-line Twitter client

LICENSE=	FFSL
LICENSE_NAME=	Floodgap Free Software License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	curl:ftp/curl \
		p5-Term-ReadLine>=1.14:devel/p5-Term-ReadLine \
		p5-TimeDate>=2.30:devel/p5-TimeDate

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	oysttyer
SHEBANG_FILES=	oysttyer.pl
PLIST_FILES=	bin/oysttyer

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL} ${WRKSRC}/oysttyer.pl ${STAGEDIR}${PREFIX}/bin/oysttyer

.include <bsd.port.mk>
