# Created by: Richard Neese <r.neese@gmail.com>
# $FreeBSD$

PORTNAME=	freeswitch
DISTVERSION=	1.2.3
CATEGORIES=	misc
MASTER_SITES=	http://files.freeswitch.org/
PKGNAMESUFFIX=	-scripts-devel
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeSwitch Scripts

RUN_DEPENDS=	freeswitch:${PORTSDIR}/net/freeswitch-core-devel

CONFLICTS=	freeswitch-scripts-[0-9]*

USE_BZIP2=	yes
NO_BUILD=	yes

FREESWITCH_USER=	freeswitch
FREESWITCH_GROUP=	${FREESWITCH_USER}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}/scripts/

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}
PORTEXAMPLES=	*

NO_STAGE=	yes
pre-su-install:
	@${RM} ${WRKSRC}/javascript/ps_pizza.js
	@${RM} ${WRKSRC}/javascript/pizza.js
	@${RM} -rf ${WRKSRC}/javascript/js_modules
	@${MKDIR} ${EXAMPLESDIR}/scripts
	@${CHOWN} ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${EXAMPLESDIR}/scripts
	@${TOUCH} ${EXAMPLESDIR}/scripts/.freeswitch-scripts
	@${CHOWN} ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${EXAMPLESDIR}/scripts/.freeswitch-scripts

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${EXAMPLESDIR}/scripts/)

	@${CHOWN} -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} \
		${EXAMPLESDIR}/scripts/

.include <bsd.port.mk>
