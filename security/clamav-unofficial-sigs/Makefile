# New ports collection makefile for:	clamav-unofficial-sigs
# Date created:		2010-03-06
# Whom:			Marko Njezic <sf@maxempire.com>
#
# $FreeBSD$
#

PORTNAME=	clamav-unofficial-sigs
PORTVERSION=	3.7.1
CATEGORIES=	security
MASTER_SITES=	http://www.inetmsg.com/pub/ \
		http://www.inetmsg.com/pub/archive/

MAINTAINER=	sf@maxempire.com
COMMENT=	Update script for third-party ClamAV databases

RUN_DEPENDS=	clamscan:${PORTSDIR}/security/clamav \
		rsync:${PORTSDIR}/net/rsync \
		curl:${PORTSDIR}/ftp/curl \
		gpg:${PORTSDIR}/security/gnupg

USE_PERL5_RUN=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

MAN8=		clamav-unofficial-sigs.8
MANCOMPRESSED=	no

SED_CONF=	-e 's|%%CLAM_DBS%%|/var/db/clamav|g' \
		-e 's|%%CLAMD_PID%%|/var/run/clamav/clamd.pid|g' \
		-e 's|%%CLAMD_SOCKET%%|/var/run/clamav/clamd.sock|g' \
		-e 's|%%START_CLAMD%%|${PREFIX}/etc/rc.d/clamav-clamd start|g' \
		-e 's|%%WORK_DIR%%|/var/db/clamav-unofficial-sigs|g'

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/clamav-unofficial-sigs.sh
	@${REINPLACE_CMD} ${SED_CONF} ${WRKSRC}/clamav-unofficial-sigs.conf
	@${REINPLACE_CMD} ${SED_CONF} ${WRKSRC}/clamd-status.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/clamav-unofficial-sigs.sh ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/clamav-unofficial-sigs.8 ${MANPREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/clamav-unofficial-sigs.conf ${PREFIX}/etc/clamav-unofficial-sigs.conf.sample

.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGELOG INSTALL LICENSE README ${DOCSDIR}
.endif

.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/clamav-unofficial-sigs-cron ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/clamav-unofficial-sigs-logrotate ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/clamd-status.sh ${EXAMPLESDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
