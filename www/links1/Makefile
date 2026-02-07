PORTNAME=	links
PORTVERSION=	1.04
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://www.jikos.cz/~mikulas/links/download/
PKGNAMESUFFIX=	1

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Lynx-like text WWW browser
WWW=		http://www.jikos.cz/~mikulas/links/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ssl

PLIST_FILES=	bin/links \
		share/man/man1/links.1.gz

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CONFLICTS=	links-2*

CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}

.include <bsd.port.mk>
