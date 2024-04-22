PORTNAME=	genplist
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Generates a static plist for a port
WWW=		http://personalpages.tds.net/~jwbacon/Ports

LICENSE=	BSD2CLAUSE

NO_BUILD=	yes
USES=		tar:xz

PLIST_FILES=	bin/genplist share/man/man1/genplist.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/genplist ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/genplist.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
