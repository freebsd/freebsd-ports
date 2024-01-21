PORTNAME=	onioncat
DISTVERSION=	4.10.0
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	https://github.com/rahra/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	IP-transparent Tor Hidden Service connector
WWW=		https://www.onioncat.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tor:security/tor

USES=		autoreconf
GNU_CONFIGURE=	yes

USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/ocat share/man/man1/ocat.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ocat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/ocat.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
