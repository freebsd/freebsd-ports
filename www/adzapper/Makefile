# New ports collection makefile for:		adzapper
# Version required:		0.1.30
# Date created:			01 Oct 1999
# Whom:                 Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

DISTNAME=	adzapper-0.1.30
CATEGORIES=	www
MASTER_SITES=	http://www.halcyon.com/adamf/adzapper/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dr@domix.de

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

NO_BUILD=	yes

post-extract:
	@${RM} -rf ${WRKSRC}/src/medusa/CVS
	@${SED} -e 's,__PREFIX__,${PREFIX},g' ${FILESDIR}/adzapper.sh > \
		${WRKSRC}/adzapper.sh
	@${SED} -e 's,__PREFIX__,${PREFIX},g' ${FILESDIR}/adzapper.sh > \
		${WRKSRC}/rc.adzapper.sh

do-install:
	${MKDIR} ${PREFIX}/share/adzapper
	${INSTALL_SCRIPT} ${WRKSRC}/adzapper.sh ${PREFIX}/sbin/adzapper
	${INSTALL_SCRIPT} ${WRKSRC}/adzapper.py ${PREFIX}/share/adzapper/
	${INSTALL_SCRIPT} ${WRKSRC}/rc.adzapper.sh ${PREFIX}/etc/rc.d/adzapper.sh
	${CP} -Rp ${WRKSRC}/zaplets ${PREFIX}/share/adzapper
	${CP} -Rp ${WRKSRC}/doc ${PREFIX}/share/adzapper
	${CP} -Rp ${WRKSRC}/src ${PREFIX}/share/adzapper
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/adzapper
	${INSTALL_DATA} ${WRKSRC}/adzapper.conf ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/adzapper.conf ${PREFIX}/etc/adzapper.conf.sample

.include <bsd.port.mk>
