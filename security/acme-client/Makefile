# Created by: Bernard Spil <brnrd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	acme-client
PORTVERSION=	0.1.11
DISTVERSIONPREFIX=	portable-
CATEGORIES=	security
MASTER_SITES=	https://kristaps.bsd.lv/${PORTNAME}/snapshots/ \
		LOCAL/brnrd

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Native C client for Let's Encrypt, designed for security

LICENSE=	ISCL

USES=		gmake ssl tar:tgz

MAKEFILE=	GNUmakefile
MAKE_ENV=	PREFIX=${STAGEDIR}/${PREFIX}

WWWDIR=		${PREFIX}/www/letsencrypt

SAMPLE_FILES=	acme-client.sh.sample deploy.sh.sample
SUB_FILES=	000.acme-client.sh pkg-message ${SAMPLE_FILES}
SUB_LIST=	PORTNAME=${PORTNAME}

PERIODIC_DIRS=	etc/periodic/weekly
PERIODIC_FILES=	000.acme-client.sh

post-patch:
	${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|" \
		-e "s|/var/www/letsencrypt|${WWWDIR}|" \
		${WRKSRC}/main.c ${WRKSRC}/acme-client.1

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PERIODIC_DIRS}
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODIC_FILES} ${STAGEDIR}${PREFIX}/${PERIODIC_DIRS}/${PERIODIC_FILES}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/acme-client
.	for d in etc/ssl/letsencrypt etc/ssl/letsencrypt/private \
		etc/letsencrypt www/letsencrypt
		${MKDIR} ${STAGEDIR}${PREFIX}/${d}
.	endfor
.	for d in ${SAMPLE_FILES}
		${INSTALL_SCRIPT} ${WRKDIR}/${d} ${STAGEDIR}${PREFIX}/etc/letsencrypt/${d}
.	endfor

.include <bsd.port.pre.mk>

.if empty(SSL_DEFAULT:M*libressl*)
IGNORE=	needs LibreSSL to build. set DEFAULT_VERSIONS+=ssl=libressl \
	and rebuild all ports that depend on openssl
.endif

.include <bsd.port.post.mk>
