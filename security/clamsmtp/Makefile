# New ports collection makefile for:	clamsmtp
# Date created:		2004-07-29
# Whom:			Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	clamsmtp
PORTVERSION=	1.6
CATEGORIES=	security
MASTER_SITES=	http://memberwebs.com/nielsen/software/clamsmtp/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	An ClamAV anti-virus SMTP Filter

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_RC_SUBR=	clamsmtpd.sh
SUB_LIST=	CLAMAV_PID_DIR=${CLAMAV_PID_DIR}

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

CLAMAV_PID_DIR?=	/var/run/clamav

MAN5=		clamsmtpd.conf.5
MAN8=		clamsmtpd.8

PORTDOCS=	*

.if exists(${LOCALBASE}/sbin/clamd)
RUN_DEPENDS+=	${LOCALBASE}/sbin/clamd:${PORTSDIR}/security/clamav
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,%%PTHREAD_LIBS%%,${PTHREAD_LIBS}," ${WRKSRC}/configure

post-install:
	@${INSTALL_DATA} ${WRKSRC}/doc/clamsmtpd.conf ${PREFIX}/etc/clamsmtpd.conf-sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/virus_action.sh ${DOCSDIR}
.endif
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${PKGMESSAGE}

.include <bsd.port.mk>
