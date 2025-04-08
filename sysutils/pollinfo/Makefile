PORTNAME=	pollinfo
DISTVERSION=	g20250404
PORTREVISION=	2
CATEGORIES=	sysutils devel

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Poll/select dumper for FreeBSD
WWW=		https://github.com/kostikbel/pollinfo

LICENSE=	BSD2CLAUSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	kostikbel
GH_TAGNAME=	0f900f2ee101fc374c1d945c4a548683438cfe46

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/pollinfo.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/pollinfo.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
