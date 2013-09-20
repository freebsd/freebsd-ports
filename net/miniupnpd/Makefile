# Created by: Daniel O'Connor <darius@dons.net.au>
# $FreeBSD$

PORTNAME=	miniupnpd
PORTVERSION=	1.8
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

OPTIONS_DEFINE=	PF_ENABLE_FILTER_RULES
PF_ENABLE_FILTER_RULES_DESC=	Enable pf generation of filter rules

NO_STAGE=	yes
.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MWITH_PF_ENABLE_FILTER_RULES}
EXTRA_PATCHES=	${PATCHDIR}/pf_enable_filter_rules.patch
.endif

post-patch-script:
	@${REINPLACE_CMD} 's|CFLAGS ?= -pipe -Os|CFLAGS ?= -pipe|' \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/miniupnpd ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKDIR}/miniupnpd.conf.sample ${PREFIX}/etc/miniupnpd.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/miniupnpd.8 ${MAN8PREFIX}/man/man8/miniupnpd.8
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
