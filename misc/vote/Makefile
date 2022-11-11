PORTNAME=	vote
DISTVERSION=	1.1
CATEGORIES=	misc
MASTER_SITES=	https://codeberg.org/tcberner/${PORTNAME}/archive/

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Transparent git based voting system

NO_BUILD=	yes

PLIST_FILES=	bin/vote

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/vote/vote ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
