# Created by: Bernard Spil <brnrd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	letskencrypt
DISTVERSIONPREFIX=	VERSION_
PORTVERSION=	0_1_5
CATEGORIES=	security

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Native C client for Let's Encrypt, designed for security

LICENSE=	ISCL

USES=		gmake
USE_GITHUB=	yes
USE_OPENSSL=	yes

GH_ACCOUNT=	kristapsdz
GH_PROJECT=	${PORTNAME}-portable

MAKEFILE=	GNUmakefile
MAKE_ARGS=	PREFIX=${STAGEDIR}/${PREFIX}

WITH_OPENSSL_PORT=	yes
OPENSSL_PORT=	security/libressl

WWWDIR=		${PREFIX}/www/letsencrypt

post-patch:
	${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|" \
		-e "s|/var/www/letsencrypt|${WWWDIR}|" \
		${WRKSRC}/main.c ${WRKSRC}/letskencrypt.1

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/letskencrypt
.	for d in etc/ssl/letsencrypt etc/ssl/letsencrypt/private \
		etc/letsencrypt www/letsencrypt 
		${MKDIR} ${STAGEDIR}${PREFIX}/${d}
.	endfor

.include <bsd.port.mk>
