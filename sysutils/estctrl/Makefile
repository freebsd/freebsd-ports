# New ports collection makefile for:	Enhanced SpeedStep control daemon
# Date created:				1 September 2004
# Whom:					cperciva@daemonology.net
#
# $FreeBSD$
#

PORTNAME=	estctrl
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.daemonology.net/freebsd-est/

MAINTAINER=	cperciva@daemonology.net
COMMENT=	Enhanced SpeedStep control daemon

RUN_DEPENDS=	${LOCALBASE}/modules/est.ko:${PORTSDIR}/sysutils/est

ONLY_FOR_ARCHS=	i386

USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

PLIST_FILES=	sbin/estctrl		\
		etc/rc.d/estctrl.sh

MAKE_ENV=	BINDIR=${PREFIX}/sbin

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 600015
IGNORE=		"estctrl now contained in the base system (see powerd(8))"
.endif

post-extract:
	${SED}	${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/}	\
		${FILESDIR}/estctrl.sh > ${WRKDIR}/estctrl.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/estctrl.sh ${PREFIX}/etc/rc.d/estctrl.sh
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
