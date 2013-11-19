# Created by: Richard Neese <r.neese@gmail.com>
# $FreeBSD$

PORTNAME=	freeswitch-pizza
PORTVERSION=	1.0.7.1
PORTEPOCH=	1
CATEGORIES=	misc
MASTER_SITES=	http://dl.dropbox.com/u/152504/ \
		http://files.freeswitch.org/:2
DISTFILES=	${BASE_PORTNAME}-${PORTVERSION}.tar.gz \
		pizza_gram.tar.gz:2 \
		pizza_sounds.tar.gz:2
DIST_SUBDIR=	${BASE_PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeSwitch pizza demo

DEPRECATED=	Depends on expired net/freeswitch-core
EXPIRATION_DATE=2013-12-19

RUN_DEPENDS=    ${LOCALBASE}/bin/freeswitch:${PORTSDIR}/net/freeswitch-core \
		${LOCALBASE}/share/${BASE_PORTNAME}/sounds/.freeswitch-sounds:${PORTSDIR}/audio/freeswitch-sounds

NO_BUILD=	yes

BASE_PORTNAME=	freeswitch

WRKSRC=	${WRKDIR}/${BASE_PORTNAME}-${PORTVERSION}/scripts/javascript

NO_STAGE=	yes
pre-install:
	@${REINPLACE_CMD} -e 's|include("js_modules/SpeechTools.jm")|include("javascript/js_modules/SpeechTools.jm")|g' ${WRKSRC}/ps_pizza.js
	@${REINPLACE_CMD} -e 's|asr.setAudioBase("/root/pizza)|asr.setAudioBase("${PREFIX}/share/${BASE_PORTNAME}/sounds/en/us/callie/pizza/8000")|g' ${WRKSRC}/ps_pizza.js

do-install:
	@cd ${WRKDIR}; ${FIND} *.gram \
		| ${CPIO} -pdm -R freeswitch:freeswitch ${PREFIX}/etc/${BASE_PORTNAME}/grammar/
	@cd ${WRKDIR}/pizza/; ${FIND} *.wav \
		| ${CPIO} -pdm -R freeswitch:freeswitch ${PREFIX}/share/${BASE_PORTNAME}/sounds/en/us/callie/pizza/8000
	${TOUCH} ${PREFIX}/share/${BASE_PORTNAME}/sounds/.pizza
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/scripts/javascript
	@cd ${WRKSRC}; ${FIND} ps_pizza.js \
		| ${CPIO} -pdm -R freeswitch:freeswitch ${PREFIX}/etc/${BASE_PORTNAME}/scripts/javascript
	@cd ${WRKSRC}; ${FIND} js_modules \
		| ${CPIO} -pdm -R freeswitch:freeswitch ${PREFIX}/etc/${BASE_PORTNAME}/scripts/javascript

.include <bsd.port.mk>
