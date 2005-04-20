# New ports collection makefile for:	clamsmtp
# Date created:		2004-07-29
# Whom:			Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	clamsmtp
PORTVERSION=	1.4.1
PORTREVISION=	0
CATEGORIES=	security
MASTER_SITES=	http://memberwebs.com/nielsen/software/clamsmtp/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	An ClamAV anti-virus SMTP Filter

RUN_DEPENDS=	${LOCALBASE}/sbin/clamd:${PORTSDIR}/security/clamav

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR} CLAMAV_PID_DIR=${CLAMAV_PID_DIR}
STARTUP_FILE=	${PREFIX}/etc/rc.d/clamsmtpd.sh

CLAMAV_PID_DIR?=	/var/run/clamav

MAN5=		clamsmtpd.conf.5
MAN8=		clamsmtpd.8

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-install:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/clamsmtpd.sh.tmpl > ${STARTUP_FILE}
	@${INSTALL_DATA} ${WRKSRC}/doc/clamsmtpd.conf ${PREFIX}/etc/clamsmtpd.conf-sample
	@${CHMOD} 755 ${STARTUP_FILE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/virus_action.sh ${DOCSDIR}
.endif
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${PKGMESSAGE}

post-patch:
	@${REINPLACE_CMD} -e "s,%%PTHREAD_LIBS%%,${PTHREAD_LIBS}," ${WRKSRC}/configure

.include <bsd.port.mk>
