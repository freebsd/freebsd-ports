# New ports collection makefile for:   sixxs-aiccu
# Date created:                2004-09-07
# Whom:                        Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	sixxs-aiccu
PORTVERSION=	20050131
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.sixxs.net/archive/sixxs/aiccu/unix/
DISTNAME=	aiccu_2005.01.31

MAINTAINER=	meno.abels@adviser.com
COMMENT=	SixXS IPv6 TIC+ tunnel broker heartbeat client

USE_RC_SUBR=	yes
USE_GMAKE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
MAKE_ARGS=	CC="${CC}"
MAKE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
WRKSRC=		${WRKDIR}/aiccu
BUILD_WRKSRC=	${WRKDIR}/aiccu/unix-console

PORTDOCS=	README

pre-build:
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:g' \
		-e 's:%%RC_SUBR%%:${RC_SUBR}:g' \
		${FILESDIR}/sixxs-aiccu.sh >${WRKDIR}/sixxs-aiccu.sh
	@${SED} \
		-e 's:verbose true:verbose false:' \
		-e 's:daemonize false:daemonize true:' \
		-e 's:automatic false:automatic true:' \
		-e 's:tunnel_id T2995:#tunnel_id TXXXX:' \
		-e 's:ipv4_interface eth0:ipv4_interface sis0:' \
		-e 's:ipv6_interface sixxs:ipv6_interface gif0:' \
		${WRKSRC}/doc/aiccu.conf > ${WRKDIR}/aiccu.conf

do-install:
	@${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/unix-console/aiccu ${PREFIX}/sbin/sixxs-aiccu
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/aiccu.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/aiccu.conf ${PREFIX}/etc/aiccu.conf.sample
	${INSTALL_SCRIPT} ${WRKDIR}/sixxs-aiccu.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
