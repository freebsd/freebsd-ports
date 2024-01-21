PORTNAME=	micro_inetd
PORTVERSION=	2014.08.14
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.acme.com/software/micro_inetd/
DISTNAME=	${PORTNAME}_14Aug2014

MAINTAINER=	pankov_p@mail.ru
COMMENT=	inetd-like program intended for temporarily usage
WWW=		https://www.acme.com/software/micro_inetd/

LICENSE=	BSD2CLAUSE

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/micro_inetd share/man/man1/micro_inetd.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micro_inetd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/micro_inetd.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
