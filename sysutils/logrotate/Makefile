# New ports collection makefile for:	logrotate
# Date Created:				29 Dec 1999
# Whom:					Yuan-Chen Cheng <ycheng@sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	logrotate
PORTVERSION=	3.5.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_REDHAT_LINUX}
MASTER_SITE_SUBDIR=	7.0/en/os/i386/SRPMS
EXTRACT_SUFX=	-1.src.rpm

MAINTAINER=	ycheng@sinica.edu.tw
COMMENT=	Daemon to rotate, compress, remove and mail system log files

EXTRACT_DEPENDS=	${LOCALBASE}/bin/rpm2cpio:${PORTSDIR}/archivers/rpm
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_GMAKE=	yes
MAN8=		logrotate.8
MANCOMPRESSED=	no

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@rpm2cpio ${_DISTDIR}${DISTFILES} | (cd ${WRKDIR}; cpio -i)
	@${TAR} -xzf ${WRKDIR}/${DISTNAME}.tar.gz -C ${WRKDIR}

post-install:
	@${MKDIR} ${PREFIX}/etc/logrotate.d
	@${SED} -e 's|__PREFIX__|${PREFIX}|' \
		< ${FILESDIR}/logrotate.conf.sample > ${PREFIX}/etc/logrotate.conf.sample
	@${INSTALL_DATA} ${FILESDIR}/syslog.sample ${PREFIX}/etc/logrotate.d/

.include <bsd.port.mk>
