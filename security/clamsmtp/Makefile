# New ports collection makefile for:	clamsmtp
# Date created:		2004-07-29
# Whom:			Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	clamsmtp
PORTVERSION=	0.5
CATEGORIES=	security
MASTER_SITES=	http://memberwebs.com/nielsen/software/clamsmtp/

MAINTAINER=	clsung@dragon2.net
COMMENT=	An ClamAV anti-virus SMTP Filter

RUN_DEPENDS=	clamd:${PORTSDIR}/security/clamav

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR} CLAMAV_USER=${CLAMAV_USER} \
		CLAMAV_PID_DIR=${CLAMAV_PID_DIR} CLAMAV_GROUP=${CLAMAV_GROUP} \
		CLAMAV_CLAMD_SOCKET=${CLAMAV_CLAMD_SOCKET}
STARTUP_FILE=	${PREFIX}/etc/rc.d/clamsmtpd.sh

CLAMAV_USER?=	clamav
CLAMAV_GROUP?=	clamav
CLAMAV_PID_DIR?=	/var/run/clamav
CLAMAV_CLAMD_SOCKET?=	/var/run/clamav/clamd

MAN8=		clamsmtpd.8

post-patch:
	@${REINPLACE_CMD} -e 's,10025,10026,g' ${WRKSRC}/src/clamsmtpd.c ${WRKSRC}/src/clamsmtpd.8

post-install:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/clamsmtpd.sh.tmpl > ${STARTUP_FILE}
	@${CHMOD} 755 ${STARTUP_FILE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
