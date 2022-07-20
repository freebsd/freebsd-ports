PORTNAME=	links
PORTVERSION=	1.04
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://www.jikos.cz/~mikulas/links/download/
PKGNAMESUFFIX=	1

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Lynx-like text WWW browser

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ssl

PLIST_FILES=	man/man1/links.1.gz \
		bin/links

GNU_CONFIGURE=	yes

CONFLICTS=	links-2*

CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}

.include <bsd.port.mk>
