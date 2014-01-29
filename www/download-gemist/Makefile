# Created by: Martin Tournoij <martin@arp242.net>
# $FreeBSD$

PORTNAME=	download-gemist
PORTVERSION=	1.2
CATEGORIES=	www python
MASTER_SITES=	http://code.arp242.net/download-gemist/downloads/

MAINTAINER=	martin@arp242.net
COMMENT=	Download videos from the Dutch uitzending gemist site

LICENSE=	MIT

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_DIRS=	%%DOCSDIR%%
PLIST_FILES=	bin/download-gemist \
		bin/download-gemist-guide \
		%%DOCSDIR%%/README.md

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/download-gemist* ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
