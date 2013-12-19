# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	genplist
PORTVERSION=	1.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Generates a static plist for a port

LICENSE=	BSD

NO_BUILD=	yes
USE_XZ=		yes

PLIST_FILES=	bin/genplist man/man1/genplist.1.gz

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/genplist ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/genplist.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
