# Created by: HSIN-HSIUNG CHANG <sexbear@tmu.edu.tw>
# $FreeBSD$

PORTNAME=	pwebstats
PORTVERSION=	1.3.8
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.gleeson.net/pub/pwebstats/dist/ \
		ftp://ftp.psg.com/pub/pwebstats/ \
		ftp://ftp.unimelb.edu.au/pub/www/tools/unix/pwebstats/

MAINTAINER=	sexbear@tmu.edu.tw
COMMENT=	Analyse a web server log

BROKEN=		unfetchable

RUN_DEPENDS=	fly:graphics/fly

USES=		perl5

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/pwebstats/
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${PREFIX}/etc/pwebstats/
	${MV} "${STAGEDIR}${PREFIX}/etc/pwebstats/templates/images/'.gif" ${STAGEDIR}${PREFIX}/etc/pwebstats/templates/images/10.gif
	${MV} "${STAGEDIR}${PREFIX}/etc/pwebstats/templates/images/dates/'.gif" ${STAGEDIR}${PREFIX}/etc/pwebstats/templates/images/dates/10.gif
	${RM} ${STAGEDIR}${PREFIX}/etc/pwebstats/pwebstats.orig

.include <bsd.port.mk>
