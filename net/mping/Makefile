# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	mping
PORTVERSION=	2.01
CATEGORIES=	net ipv6
MASTER_SITES=	http://mping.uninett.no/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mping network statistics collector

GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/mping \
		man/man8/mping.8.gz
PORTDOCS=	ChangeLog README TODO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mping ${STAGEDIR}${PREFIX}/sbin/mping
	${INSTALL_MAN} ${WRKSRC}/man/mping.8 ${STAGEDIR}${PREFIX}/man/man8/mping.8
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
