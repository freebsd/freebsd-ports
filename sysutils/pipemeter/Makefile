PORTNAME=	pipemeter
PORTVERSION=	1.1.5
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpadlibrarian.net/516365027/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tool for displaying pipe status information

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pipemeter \
		man/man1/pipemeter.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipemeter ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pipemeter.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
