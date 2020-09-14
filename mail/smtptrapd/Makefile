# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smtptrapd
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RFC 2821 compliant SMTP service that always returns a 4xx soft error

USE_RC_SUBR=	smtptrapd

LICENSE=	GPLv2

PLIST_FILES=	bin/smtptrapd \
		"@dir(,,0755) /var/run/smtptrapd-root"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${CC} ${CFLAGS} -lpthread -o smtptrapd smtptrapd.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smtptrapd ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}/var/run/smtptrapd-root

.include <bsd.port.mk>
