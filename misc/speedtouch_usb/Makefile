# New ports collection makefile for:	speedtouch_usb
# Date created:				7 August 2001
# Whom:					Nick Hibma
#
# $FreeBSD$
#

PORTNAME=	speedtouch
PORTVERSION=	21062001
CATEGORIES=	misc
MASTER_SITES=	http://www.xsproject.org/speedtouch/files/ \
		http://www.alcatel.com/consumer/dsl/
DISTFILES=	speedtouch-${PORTVERSION}.tar.gz \
		speedmgmt.tar.gz

MAINTAINER=	ports@FreeBSD.org

do-install:
	[ -d ${PREFIX} ] || ${MKDIR} ${PREFIX}
	${INSTALL_PROGRAM} ${WRKSRC}/modem_run ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/pppoa2 ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKDIR}/mgmt/mgmt.o ${PREFIX}/libdata

	@${ECHO} "#!/bin/sh" > ${WRKDIR}/adsl.sh.sample
	@${ECHO} "PREFIX=${PREFIX}" >> ${WRKDIR}/adsl.sh.sample
	${CAT} files/adsl.sh.sample >> ${WRKDIR}/adsl.sh.sample
	${INSTALL_SCRIPT} ${WRKDIR}/adsl.sh.sample ${PREFIX}/etc/rc.d/

	${INSTALL_DATA} files/adsl.conf.sample /etc/ppp/

	@${CAT} files/configuration

.include <bsd.port.mk>
