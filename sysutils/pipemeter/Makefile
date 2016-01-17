# Created by: Len Sassama
# $FreeBSD$

PORTNAME=	pipemeter
PORTVERSION=	1.1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpadlibrarian.net/57215122/ \
		http://spamaps.org/files/pipemeter/

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
