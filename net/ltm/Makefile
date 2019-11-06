# Created by: Statseeker
# $FreeBSD$

PORTNAME=	ltm
PORTVERSION=	3.0.0.608281003
CATEGORIES=	net
MASTER_SITES=	http://www.statseeker.com/downloads/

MAINTAINER=	ltm-support@statseeker.com
COMMENT=	Statseeker Real Time LAN Analyser

BROKEN=		unfetchable

NO_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ltm-client ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ltm-mkprotodb ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/etc/protocols.cfg ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/etc/protocols.db ${STAGEDIR}${PREFIX}/etc
.for f in ltm-client ltm-mkprotodb ltm
	${INSTALL_MAN} ${WRKSRC}/man/man1/${f}.1.gz \
		${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
