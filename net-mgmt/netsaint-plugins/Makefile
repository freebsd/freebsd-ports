# New ports collection makefile for:	netsaint-plugins
# Date created:				Wed 12 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	netsaint-plugins
PORTVERSION=	1.2.9.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	netsaintplug
DISTNAME=	${PORTNAME}-1.2.9-4

MAINTAINER=	ports@FreeBSD.org

USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sbindir=${PREFIX}/share/netsaint/sbin \
		--libexecdir=${PREFIX}/libexec/netsaint \
		--datadir=${PREFIX}/share/netsaint \
		--sysconfdir=${PREFIX}/etc/netsaint \
		--localstatedir=${PREFIX}/var/netsaint
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		MKDIR="${MKDIR}"
USE_AUTOMAKE=	yes
USE_GMAKE=	yes

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.mk>
