# New ports collection makefile for:	adzapper
# Date created:				01 Oct 1999
# Whom:					Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	adzapper
PORTVERSION=	0.3.0
CATEGORIES=	www
MASTER_SITES=	http://www.zaplet.org/adzapper/ \
		ftp://ftp.aquezada.com/pub/distrib/adzapper/

MAINTAINER=	jdunn@aquezada.com

USE_PYTHON=	yes

do-configure:
	@${SED} -e 's,__PREFIX__,${PREFIX},g' ${FILESDIR}/adzapper.sh > \
		${WRKSRC}/adzapper.sh
	@${SED} -e 's,__PREFIX__,${PREFIX},g' ${FILESDIR}/rc.adzapper.sh > \
		${WRKSRC}/rc.adzapper.sh

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	${MKDIR} ${PREFIX}/share/adzapper
	${INSTALL_SCRIPT} ${WRKSRC}/adzapper.sh ${PREFIX}/sbin/adzapper
	${INSTALL_SCRIPT} ${WRKSRC}/adzapper.py ${PREFIX}/share/adzapper/
	${INSTALL_SCRIPT} ${WRKSRC}/rc.adzapper.sh ${PREFIX}/etc/rc.d/adzapper.sh.sample
	@if [ -d ${PREFIX}/share/adzapper/zaplets ]; then \
		${MV} -f ${PREFIX}/share/adzapper/zaplets ${PREFIX}/share/adzapper/zaplets.old; \
	fi
.for dir in doc dtml src zaplets
	${CP} -Rp ${WRKSRC}/${dir} ${PREFIX}/share/adzapper
.endfor
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/adzapper
	${INSTALL_DATA} ${WRKSRC}/adzapper.conf ${PREFIX}/etc/adzapper.conf.default
	@${ECHO_MSG} "===> Copy the ${PREFIX}/etc/adzapper.conf.default to ${PREFIX}/etc/adzapper.conf,"
	@${ECHO_MSG} "===> adding your own customizations, before starting adzapperd."

.include <bsd.port.mk>
