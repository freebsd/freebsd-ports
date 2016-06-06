# Created by: Bernard Spil <brnrd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	letskencrypt
PORTVERSION=	0.1.6
DISTVERSIONPREFIX=	portable-
CATEGORIES=	security
MASTER_SITES=	https://kristaps.bsd.lv/letskencrypt/snapshots/ \
		LOCAL/brnrd

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Native C client for Let's Encrypt, designed for security

LICENSE=	ISCL

USES=		gmake tar:tgz
USE_OPENSSL=	yes

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
