PORTNAME=	zfsnap
PORTVERSION=	1.11.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Simple sh script to make zfs rolling snaphosts with cron

LICENSE=	BSD3CLAUSE

NO_BUILD=	yes
USE_GITHUB=	yes

PERIODICDIR?=	${PREFIX}/etc/periodic
PLIST_SUB+=	PERIODICDIR="${PERIODICDIR:S,^${PREFIX}/,,}"

post-extract:
.for period in hourly daily weekly monthly reboot
	@${SED} -e "s/xPERIODICx/${period}/g" -e "s#xPREFIXx#${PREFIX}/sbin#g" ${WRKSRC}/xPERIODICx_zfSnap.sh > ${WRKSRC}/${period}_zfSnap.sh
.endfor
.for period in hourly daily weekly monthly
	@${SED} -e "s/xPERIODICx/${period}/g" -e "s#xPREFIXx#${PREFIX}/sbin#g" ${WRKSRC}/xPERIODICx_zfSnap_delete.sh > ${WRKSRC}/${period}_zfSnap_delete.sh
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zfSnap.sh ${STAGEDIR}${PREFIX}/sbin/zfSnap
.for period in hourly daily weekly monthly
	@${MKDIR} ${STAGEDIR}${PERIODICDIR}/${period}
	${INSTALL_SCRIPT} ${WRKSRC}/${period}_zfSnap.sh ${STAGEDIR}${PERIODICDIR}/${period}/402.zfSnap
	${INSTALL_SCRIPT} ${WRKSRC}/${period}_zfSnap_delete.sh ${STAGEDIR}${PERIODICDIR}/${period}/403.zfSnap_delete
.endfor
	@${MKDIR} ${STAGEDIR}${PERIODICDIR}/reboot
	${INSTALL_SCRIPT} ${WRKSRC}/reboot_zfSnap.sh ${STAGEDIR}${PERIODICDIR}/reboot/402.zfSnap

.include <bsd.port.mk>
