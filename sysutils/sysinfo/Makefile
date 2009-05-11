# New ports collection makefile for:		sysinfo
# Date created:					22 April 2009
# Whom:						Daniel Gerzo <danger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sysinfo
PORTVERSION=	0.8.7
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://danger.rulez.sk/projects/sysinfo/
MASTER_SITE_SUBDIR=danger

MAINTAINER=	danger@FreeBSD.org
COMMENT=	Utility used to gather system configuration information

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN5=		sysinfo.conf.5
MAN8=		sysinfo.8

OPTIONS=	DMIDECODE "Include information from the dmidecode tool" Off \
		PORTAUDIT "Include information from the portaudit tool" Off

.include <bsd.port.pre.mk>

.if defined(WITH_DMIDECODE)
RUN_DEPENDS=	dmidecode:${PORTSDIR}/sysutils/dmidecode
.endif

.if defined(WITH_PORTAUDIT)
RUN_DEPENDS+=	portaudit:${PORTSDIR}/ports-mgmt/portaudit
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|common.subr|${DATADIR}/common.subr|g' ${WRKSRC}/sysinfo
	@${REINPLACE_CMD} -e 's|sysinfo.conf|${PREFIX}/etc/sysinfo.conf|g' \
		${WRKSRC}/sysinfo ${WRKSRC}/doc/sysinfo.conf.5
	@${REINPLACE_CMD} -e 's|APPDIR=.|APPDIR=${DATADIR}|g' \
		${WRKSRC}/sysinfo.conf ${WRKSRC}/doc/sysinfo.conf.5

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sysinfo ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/sysinfo.conf ${PREFIX}/etc/sysinfo.conf.sample

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/common.subr ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE ${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_BIN} modules ${DATADIR})

.if !defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/doc/sysinfo.conf.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/sysinfo.8 ${MANPREFIX}/man/man8
.endif

	@if [ ! -f ${PREFIX}/etc/sysinfo.conf ]; then \
		${CP} -p ${PREFIX}/etc/sysinfo.conf.sample ${PREFIX}/etc/sysinfo.conf ; \
	fi

.include <bsd.port.post.mk>
