# New ports collection makefile for:	nagios-plugins
# Date created:				14 Jul 2002
# Whom:					Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nagios-plugins
PORTVERSION=	1.3.b1
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nagiosplug
DISTNAME=	nagiosplug-1.3-beta1

MAINTAINER=	blaz@si.FreeBSD.org

USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sbindir=${PREFIX}/share/nagios/sbin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datadir=${PREFIX}/share/nagios \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=${PREFIX}/var/nagios
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		MKDIR="${MKDIR}"
USE_AUTOMAKE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.mk>
