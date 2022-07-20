PORTNAME=	minirsyslogd
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	http://redundancy.redundancy.org/mirror/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Minimal, fast and secure syslog receiver

USE_RC_SUBR=	minirsyslogd

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8.gz \
		${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
