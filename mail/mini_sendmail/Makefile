# Ports collection makefile for:	mini_sendmail
# Date created:				11 July 2003
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mini_sendmail
PORTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES+=	mail
MASTER_SITES=	http://www.acme.com/software/mini_sendmail/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Tiny MTA with only smart relay capability

MAN8=		mini_sendmail.8
PLIST_FILES=	bin/mini_sendmail

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -static -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>
