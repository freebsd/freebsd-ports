# New ports collection makefile for:   verlihub-plugins
# Date created:        3 April 2004
# Whom:                Skylord
#
# $FreeBSD$
#

PORTNAME=	verlihub
PORTVERSION=	1.0
CATEGORIES=	net-p2p
MASTER_SITES=	# empty
PKGNAMESUFFIX=	-plugins
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	skylord@vt.net.ru
COMMENT=	Meta-port for VerliHub plugins

RUN_DEPENDS=	\
		${LOCALBASE}/lib/libchatroom_pi.so:${PORTSDIR}/net-p2p/verlihub-plugins-chatroom \
		${LOCALBASE}/lib/libfloodprot_pi.so:${PORTSDIR}/net-p2p/verlihub-plugins-floodprotect \
		${LOCALBASE}/lib/libforbid_pi.so:${PORTSDIR}/net-p2p/verlihub-plugins-forbid \
		${LOCALBASE}/lib/libiplog_pi.so:${PORTSDIR}/net-p2p/verlihub-plugins-iplog \
		${LOCALBASE}/lib/libisp_pi.so:${PORTSDIR}/net-p2p/verlihub-plugins-isp \
		${LOCALBASE}/lib/liblua_pi.so:${PORTSDIR}/net-p2p/verlihub-plugins-luascript \
		${LOCALBASE}/lib/libmessanger_pi.so:${PORTSDIR}/net-p2p/verlihub-plugins-messanger \
		${LOCALBASE}/lib/libstats_pi.so:${PORTSDIR}/net-p2p/verlihub-plugins-stats

NO_BUILD=	yes

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
