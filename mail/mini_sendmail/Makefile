PORTNAME=	mini_sendmail
PORTVERSION=	1.3.9
PORTREVISION=	1
CATEGORIES+=	mail
MASTER_SITES=	http://www.acme.com/software/mini_sendmail/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Tiny MTA with only smart relay capability
WWW=		https://www.acme.com/software/mini_sendmail/

PLIST_FILES=	bin/mini_sendmail share/man/man8/mini_sendmail.8.gz

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -static -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
