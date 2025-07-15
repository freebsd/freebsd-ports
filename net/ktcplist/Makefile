PORTNAME=	ktcplist
DISTVERSION=	1.0.2
CATEGORIES=	net sysutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	List tcp connections with KTLS offload
WWW=		https://github.com/kostikbel/ktcplist

LICENSE=	BSD2CLAUSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	kostikbel
GH_TAGNAME=	${PORTNAME}-${DISTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/ktcplist.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/ktcplist.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
