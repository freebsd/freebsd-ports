# New ports collection makefile for:	qtools
# Date created:				3 July 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	qtools
PORTVERSION=	0.56
CATEGORIES=	mail
MASTER_SITES=	http://www.superscript.com/qtools/

MAINTAINER=	petef@FreeBSD.org

RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail

ALL_TARGET=	it
INSTALL_TARGET=	setup check

.if exists(${PREFIX}/qmail/bin/qmail-send)
QMAIL_DIR?=	${PREFIX}/qmail
.else
QMAIL_DIR?=	/var/qmail
.endif

NO_PACKAGE=	A possibly inherited DJB-style license would prohibit \
		distribution of modified binary packages

post-patch:
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} ${CFLAGS} ${STRIP}" > ${WRKSRC}/conf-ld
	@${PERL} -pi -e 's!/usr/local!${PREFIX}!g' ${WRKSRC}/conf-home

.include <bsd.port.mk>
