# New ports collection makefile for:	logrotate
# Date Created:				29 Dec 1999
# Whom:					Yuan-Chen Cheng <ycheng@sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=		logrotate
PORTVERSION=		3.7
PORTREVISION=		4
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_DEBIAN_POOL}
MASTER_SITE_SUBDIR=	l/logrotate
DISTNAME=		${PORTNAME}_${PORTVERSION}.orig

PATCH_SITES=		${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCHFILES=		${PORTNAME}_${PORTVERSION}-5.diff.gz

MAINTAINER=		js@iksz.hu
COMMENT=		Daemon to rotate, compress, remove and mail system log files

LIB_DEPENDS=		popt.0:${PORTSDIR}/devel/popt

USE_GMAKE=	yes
MAKE_ENV=	"BASEDIR=${PREFIX}"
PATCH_WRKSRC=		${WRKDIR}
WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN8=		logrotate.8
MANCOMPRESSED=	no

post-install:
	@${MKDIR} ${PREFIX}/etc/logrotate.d
	@${SED} -e 's|__PREFIX__|${PREFIX}|' \
		< ${FILESDIR}/logrotate.conf.sample > ${PREFIX}/etc/logrotate.conf.sample
	@${INSTALL_DATA} ${FILESDIR}/syslog.sample ${PREFIX}/etc/logrotate.d/

.include <bsd.port.mk>
