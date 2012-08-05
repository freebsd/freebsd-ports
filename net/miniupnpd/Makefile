# New ports collection makefile for:	miniupnpd
# Date created:		22 March 2007
# Whom:			Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	miniupnpd
PORTVERSION=	1.7
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://miniupnp.tuxfamily.org/files/ \
		http://miniupnp.free.fr/files/

MAINTAINER=	squat@squat.no
COMMENT=	A UPnP IGD implementation which uses pf/ipf

SUB_FILES=	miniupnpd.conf.sample
SUB_LIST=	UUID=${UUID}

UUID!=		uuidgen
FWNAME?=	pf
PLIST_FILES=	etc/miniupnpd.conf.sample sbin/miniupnpd
MAKE_JOBS_UNSAFE=yes

MAN8=		miniupnpd.8

USE_RC_SUBR=	miniupnpd

OPTIONS=	PF_ENABLE_FILTER_RULES		"Enable pf generation of filter rules" off

.include <bsd.port.options.mk>
.if defined(WITH_PF_ENABLE_FILTER_RULES)
EXTRA_PATCHES=	${PATCHDIR}/pf_enable_filter_rules.patch
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/miniupnpd ${PREFIX}/sbin/miniupnpd
	@${INSTALL_DATA} ${WRKDIR}/miniupnpd.conf.sample ${PREFIX}/etc/miniupnpd.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/miniupnpd.1 ${PREFIX}/man/man8/miniupnpd.8
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
