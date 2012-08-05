# Ports collection makefile for:	smtptrapd
# Date created:				19 March 2005
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smtptrapd
PORTVERSION=	1.6
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	RFC 2821 compliant SMTP service that always returns a 4xx soft error

CFLAGS+=	${PTHREAD_CFLAGS} ${PTHREAD_LIBS}

USE_RC_SUBR=	smtptrapd

PLIST_FILES=	bin/smtptrapd

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -o smtptrapd smtptrapd.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/smtptrapd ${PREFIX}/bin/
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
