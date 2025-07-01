PORTNAME=	ktcplist
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	net sysutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	List tcp connections with KTLS offload
WWW=		https://github.com/kostikbel/ktcplist

LICENSE=	BSD2CLAUSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	kostikbel
GH_TAGNAME=	18077c4df543d23ced0c08a6a8329e43c184ac75

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/ktcplist.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/ktcplist.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
