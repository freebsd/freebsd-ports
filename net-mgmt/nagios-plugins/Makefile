# New ports collection makefile for:	nagios-plugins
# Date created:				14 Jul 2002
# Whom:					Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nagios-plugins
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nagiosplug

MAINTAINER=	blaz@si.FreeBSD.org
COMMENT=	Plugins for nagios

USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sbindir=${PREFIX}/share/nagios/cgi-bin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datadir=${PREFIX}/share/nagios \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=/var/spool/nagios \
		--with-df-command="/bin/df -Pkt noprocfs"
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

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOMAKE_ENV} ${ACLOCAL} \
		--acdir=${ACLOCAL_DIR})

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.mk>
