# Created by: Martin Tournoij <martin@arp242.net>
# $FreeBSD$

PORTNAME=	download-gemist
PORTVERSION=	1.2
CATEGORIES=	www python
MASTER_SITES=	http://code.arp242.net/download-gemist/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Download videos from the Dutch uitzending gemist site

LICENSE=	MIT

BROKEN=		does not work (needs to be updated to the latest version)

USES=		python
NO_BUILD=	yes

PLIST_FILES=	bin/download-gemist \
		bin/download-gemist-guide \
		%%DOCSDIR%%/README.md

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/download-gemist* ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
