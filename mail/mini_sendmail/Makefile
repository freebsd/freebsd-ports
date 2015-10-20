# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mini_sendmail
PORTVERSION=	1.3.9
CATEGORIES+=	mail
MASTER_SITES=	http://www.acme.com/software/mini_sendmail/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Tiny MTA with only smart relay capability

PLIST_FILES=	bin/mini_sendmail man/man8/mini_sendmail.8.gz

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -static -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
