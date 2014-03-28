# Created by: Dean Hollister <dean@odyssey.apana.org.au>
# $FreeBSD$

PORTNAME=	fakeident
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	Tool that replies with a standard answer to incoming identd requests

PLIST_FILES=	etc/rc.d/fakeident.sh sbin/identd

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/identd ${WRKSRC}/identd.c

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/identd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${FILESDIR}/fakeident.sh ${STAGEDIR}${PREFIX}/etc/rc.d

.include <bsd.port.mk>
