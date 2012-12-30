# Created by: Aldis Berjoza <aldis@bsdroot.lv>
# $FreeBSD$

PORTNAME=	zfsnap
PORTVERSION=	1.11.0
CATEGORIES=	sysutils

MAINTAINER=	graudeejs@gmail.com
COMMENT=	Simple sh script to make zfs rolling snaphosts with cron

NO_BUILD=	yes
USE_GITHUB=	yes
GH_PROJECT=	zfSnap
GH_ACCOUNT=	graudeejs
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	2228749

PERIODICDIR?=	${PREFIX}/etc/periodic
PLIST_SUB+=	PERIODICDIR="${PERIODICDIR:S,^${PREFIX}/,,}"

do-patch:
.for period in hourly daily weekly monthly reboot
	@${SED} -e "s/xPERIODICx/${period}/g" -e "s#xPREFIXx#${PREFIX}/sbin#g" ${WRKSRC}/xPERIODICx_zfSnap.sh > ${WRKSRC}/${period}_zfSnap.sh
.endfor
.for period in hourly daily weekly monthly
	@${SED} -e "s/xPERIODICx/${period}/g" -e "s#xPREFIXx#${PREFIX}/sbin#g" ${WRKSRC}/xPERIODICx_zfSnap_delete.sh > ${WRKSRC}/${period}_zfSnap_delete.sh
.endfor

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/zfSnap.sh ${PREFIX}/sbin/zfSnap
.for period in hourly daily weekly monthly
	@${MKDIR} ${PERIODICDIR}/${period}
	@${INSTALL_SCRIPT} ${WRKSRC}/${period}_zfSnap.sh ${PERIODICDIR}/${period}/402.zfSnap
	@${INSTALL_SCRIPT} ${WRKSRC}/${period}_zfSnap_delete.sh ${PERIODICDIR}/${period}/403.zfSnap_delete
.endfor
	@${MKDIR} ${PERIODICDIR}/reboot
	@${INSTALL_SCRIPT} ${WRKSRC}/reboot_zfSnap.sh ${PERIODICDIR}/reboot/402.zfSnap

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
