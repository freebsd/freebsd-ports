# Created by: Pankov Pavel <pankov_p@mail.ru>
# $FreeBSD$

PORTNAME=	micro_inetd
PORTVERSION=	2005.06.29
CATEGORIES=	net
MASTER_SITES=	http://www.acme.com/software/micro_inetd/
DISTNAME=	${PORTNAME}_29jun2005

MAINTAINER=	pankov_p@mail.ru
COMMENT=	A inetd-like program intended for temporarily usage

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/micro_inetd man/man1/micro_inetd.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micro_inetd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/micro_inetd.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
