# Ports collection makefile for: freeswitch pizza demo
# Date created: september , 2009
# Whom: Richard Neese <r.neese@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	freeswitch-pizza
PORTVERSION=	1.0.6
CATEGORIES=	misc
MASTER_SITES=	http://files.freeswitch.org/
DISTFILES=	${BASE_PORTNAME}-${PORTVERSION}.tar.gz \
		pizza_gram.tar.gz \
		pizza_sounds.tar.gz
#EXTRACT_ONLY=	${BASE_PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	r.neese@gmail.com
COMMENT=	FreeSwitch pizza demo

RUN_DEPENDS=	${LOCALBASE}/bin/freeswitch:${PORTSDIR}/net/freeswitch-core

NO_BUILD=	yes

BASE_PORTNAME=	freeswitch

WRKSRC=		${WRKDIR}/${BASE_PORTNAME}-${PORTVERSION}/scripts/javascript

do-install:
	@cd ${WRKDIR}; ${FIND} *.gram \
		| ${CPIO} -pdm -R freeswitch:freeswitch ${PREFIX}/etc/${BASE_PORTNAME}/grammar/
	@cd ${WRKDIR}; ${FIND} pizza \
		| ${CPIO} -pdm -R freeswitch:freeswitch ${PREFIX}/share/${BASE_PORTNAME}/sounds/
	${TOUCH} ${PREFIX}/share/${BASE_PORTNAME}/sounds/.pizza
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/scripts/javascript
	@cd ${WRKSRC}; ${FIND} ps_pizza.js \
		| ${CPIO} -pdm -R freeswitch:freeswitch ${PREFIX}/etc/${BASE_PORTNAME}/scripts/javascript
	@cd ${WRKSRC}; ${FIND} js_modules \
		| ${CPIO} -pdm -R freeswitch:freeswitch ${PREFIX}/etc/${BASE_PORTNAME}/scripts/javascript

.include <bsd.port.mk>
