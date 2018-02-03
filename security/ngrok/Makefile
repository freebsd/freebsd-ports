# Created by: John Hixson <jhixson@gmail.com>
# $FreeBSD$

PORTNAME=	ngrok
PORTVERSION=	2.2.8
CATEGORIES=	security
MASTER_SITES=	https://bin.equinox.io/c/4VmDzA7iaHb/
DISTNAME=	${PORTNAME}-stable-freebsd-${ARCH:S/i386/386/:S/x86_64/amd64/}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	jhixson@gmail.com
COMMENT=	Secure tunnels to localhost

# run 'ngrok credits' for details
LICENSE=	NONE APACHE20 BSD3CLAUSE CC0-1.0 LGPL3+ MIT
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	amd64 i386

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/ngrok

NO_BUILD=	yes
USES=		zip

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
