# New ports collection makefile for:	www/vtiger-customerportal
# Date created:				22 September  2007
# Whom:					Aron Schlesinger <as@bsdgroup.de>
#
# $FreeBSD$

PORTNAME=	customerportal
PORTVERSION=	5.0.3
CATEGORIES=	www
MASTER_SITES=	SF/vtigercrm/vtiger%20CRM%20${PORTVERSION}/Add-ons
PKGNAMEPREFIX=	vtiger-
DISTNAME=	vtigercrm-customerportal-${DISTVERSION}

MAINTAINER=	as@bsdgroup.de
COMMENT=	Vtiger Customer Portal is an add-on package for vtiger CRM

NO_BUILD=	YES
NO_WRKSUBDIR=	YES

VTIGERDIR?=	${PREFIX}/www/vtiger
PORTALDIR?=	${PORTNAME}
WWWDIR?=	${VTIGERDIR}/${PORTALDIR}

RUN_DEPENDS+=	${VTIGERDIR}:${PORTSDIR}/www/vtiger

USE_ZIP=	YES
SUB_FILES=	pkg-message

CONFIG=		PortalConfig.php

do-install:
	@${FIND} ${WRKSRC} -type d | ${SED} 's,^${WRKSRC},${WWWDIR},' | ${XARGS} ${MKDIR}
	@${FIND} -s ${WRKSRC} -type f -not -name '.*' -and -not \
		-name ${CONFIG} -exec ${SH} -c '${INSTALL_DATA} -v {} \
		$$(${ECHO} {} | ${SED} "s,^${WRKSRC},${WWWDIR},")' \;
	${INSTALL_DATA} ${WRKSRC}/${CONFIG} ${WWWDIR}/${CONFIG}.sample

post-install:
.if !exists(${WWWDIR}/${CONFIG})
	${INSTALL_DATA} ${WWWDIR}/${CONFIG}.sample ${WWWDIR}/${CONFIG}
	@${CHMOD} u+w ${WWWDIR}/${CONFIG}
.endif
	@${CAT} ${PKGMESSAGE}

create-plist:
	@${FIND} -s ${WRKSRC} -type f -not -name '.*' -and -not -name ${CONFIG} \
		| ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' > ${PLIST}
	@${ECHO_CMD} '@unexec if cmp -s %D/%%WWWDIR%%/${CONFIG}.sample %D/%%WWWDIR%%/${CONFIG}; \
		then ${RM} -f %D/%%WWWDIR%%/${CONFIG}; fi' >> ${PLIST}
	@${ECHO_CMD} '%%WWWDIR%%/${CONFIG}.sample' >> ${PLIST}
	@${ECHO_CMD} '@exec if [ ! -f %D/%%WWWDIR%%/${CONFIG} ]; then \
		${INSTALL_DATA} %D/%%WWWDIR%%/${CONFIG}.sample %D/%%WWWDIR%%/${CONFIG}; \
		${CHMOD} u+w %D/%%WWWDIR%%/${CONFIG}; fi' >> ${PLIST}
	@${FIND} -ds ${WRKSRC} -type d \
		| ${SED} -e 's,^${WRKSRC},@dirrm %%WWWDIR%%,' >> ${PLIST}

.include <bsd.port.mk>
