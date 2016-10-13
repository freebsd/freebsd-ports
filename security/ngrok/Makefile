# Created by: John Hixson <jhixson@gmail.com>
# $FreeBSD$

PORTNAME=	ngrok
PORTVERSION=	2.1.14
CATEGORIES=	security
MASTER_SITES=	https://bin.equinox.io/c/4VmDzA7iaHb/
DISTNAME=	${PORTNAME}-stable-freebsd-${NGROK_ARCH}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	jhixson@gmail.com
COMMENT=	Secure tunnels to localhost

ONLY_FOR_ARCHS=	i386 amd64

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/ngrok

NO_BUILD=	yes
USES=		zip

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
NGROK_ARCH=	386
.endif
.if ${ARCH} == "amd64"
NGROK_ARCH=	amd64
.endif

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
