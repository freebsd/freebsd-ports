# New ports collection makefile for:	zfsnap
# Date created:				2010-08-02
# Whom:					Aldis Berjoza <aldis@bsdroot.lv>
#
# $FreeBSD$
#

PORTNAME=	zfsnap
PORTVERSION=	1.9.2
CATEGORIES=	sysutils
MASTER_SITES=	http://files.bsdroot.lv/my/FreeBSD/distfiles/
DISTNAME=	zfSnap-${PORTVERSION}

MAINTAINER=	aldis@bsdroot.lv
COMMENT=	Simple sh script to make zfs rolling snaphosts with cron

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/zfSnap-${REV}
REV=		a47a7d2a59b0

PERIODICDIR?=	${PREFIX}/etc/periodic
PLIST_SUB+=	PERIODICDIR="${PERIODICDIR:S,^${PREFIX}/,,}"

do-patch:
.for period in hourly daily weekly monthly reboot
	@${SED} -e "s/xPERIODICx/${period}/g" -e "s#xPREFIXx#${PREFIX}/sbin#g" ${WRKSRC}/xPERIODICx_zfSnap.sh > ${WRKSRC}/${period}_zfSnap.sh
.endfor
.for period in daily weekly monthly
	@${SED} -e "s/xPERIODICx/${period}/g" -e "s#xPREFIXx#${PREFIX}/sbin#g" ${WRKSRC}/xPERIODICx_zfSnap_delete.sh > ${WRKSRC}/${period}_zfSnap_delete.sh
.endfor

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/zfSnap.sh ${PREFIX}/sbin/zfSnap
.for period in hourly daily weekly monthly reboot
	@${MKDIR} ${PERIODICDIR}/${period}
	@${INSTALL_SCRIPT} ${WRKSRC}/${period}_zfSnap.sh ${PERIODICDIR}/${period}/402.zfSnap
.endfor
.for period in daily weekly monthly
	@${INSTALL_SCRIPT} ${WRKSRC}/${period}_zfSnap_delete.sh ${PERIODICDIR}/${period}/403.zfSnap_delete
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
