# New ports collection makefile for:		sysinfo
# Date created:					22 April 2009
# Whom:						Daniel Gerzo <danger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sysinfo
PORTVERSION=	0.8.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://danger.rulez.sk/projects/sysinfo/
MASTER_SITE_SUBDIR=danger

MAINTAINER=	danger@FreeBSD.org
COMMENT=	Utility used to gather system configuration information

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|common.subr|${DATADIR}/common.subr|g' ${WRKSRC}/sysinfo
	@${REINPLACE_CMD} -e 's|sysinfo.conf|${PREFIX}/etc/sysinfo.conf|g' ${WRKSRC}/sysinfo
	@${REINPLACE_CMD} -e 's|APPDIR=.|APPDIR=${DATADIR}|g' ${WRKSRC}/sysinfo.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sysinfo ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/sysinfo.conf ${PREFIX}/etc/sysinfo.conf.sample

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/common.subr ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE ${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_BIN} modules ${DATADIR})

	@if [ ! -f ${PREFIX}/etc/sysinfo.conf ]; then \
		${CP} -p ${PREFIX}/etc/sysinfo.conf.sample ${PREFIX}/etc/sysinfo.conf ; \
	fi

.include <bsd.port.mk>
