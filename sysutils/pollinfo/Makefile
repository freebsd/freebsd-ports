PORTNAME=	pollinfo
PORTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	sysutils devel

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Poll/select dumper for FreeBSD
WWW=		https://github.com/kostikbel/pollinfo

LICENSE=	BSD2CLAUSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	kostikbel
GH_TAGNAME=	dbfc1c25d289c18c21e20c7ef5a0013e84724190

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/pollinfo.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/pollinfo.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
