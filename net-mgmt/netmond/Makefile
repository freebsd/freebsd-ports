# New ports collection makefile for:	netmond
# Date created:				2004 Mar 30
# Whom:					vfom@narod.ru
#
# $FreeBSD$
#

PORTNAME=	netmond
PORTVERSION=	2.2b6
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.risp.ru/pub/RinetSoftware/
DISTNAME=	netmond-2.2-b6
EXTRACT_SUFX=	.tgz

MAINTAINER=	vfom@narod.ru
COMMENT=	Netmond - IP network monitoring daemon

#MK_IFGRAPH=	yes

.if defined(MK_IFGRAPH)
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
.else
CONFIGURE_ARGS=	--without-ifgraph
.endif

GNU_CONFIGURE=	yes
USE_BISON=	yes

BINOWN=		root
BINGRP=		netmon
BINMODE=	0550

PLIST_FILES=	sbin/netmond sbin/netmond_watchdog sbin/netmondctl \
		etc/netmond.conf.sample
.if defined(MK_IFGRAPH)
PLIST_FILES+=	sbin/ifgraph
.endif

USE_RC_SUBR=	netmond.sh

SUB_FILES+=	pkg-message netmond_watchdog netmondctl

PORTDOCS=	README README.ru CHANGES README.port README.port.ru

pre-build:
	${CP} ${FILESDIR}/*.c ${WRKSRC}

do-install:
	@if pw user show netmon 2>/dev/null ; then \
	    ${ECHO} "User 'netmon' exists." ; \
	else \
	    pw useradd -n netmon -g wheel -c 'Network monitor account' -s /usr/sbin/nologin ; \
	fi
	@if pw group show ${BINGRP} 2>/dev/null ; then \
	    ${ECHO} "Group '${BINGRP}' exists." ;  \
	else \
	    pw groupadd ${BINGRP} -M root,netmon ; \
	fi
	${INSTALL_PROGRAM} ${WRKSRC}/netmond      ${PREFIX}/sbin/netmond
.if defined(MK_IFGRAPH)
	${INSTALL_PROGRAM} ${WRKSRC}/ifgraph      ${PREFIX}/sbin/ifgraph
.endif
	${INSTALL_SCRIPT}   ${WRKDIR}/netmond_watchdog ${PREFIX}/sbin/netmond_watchdog
	${INSTALL_SCRIPT}   ${WRKDIR}/netmondctl ${PREFIX}/sbin/netmondctl
	${INSTALL_DATA} ${WRKSRC}/netmon.conf.sample ${PREFIX}/etc//netmond.conf.sample
	${CHMOD} u+s ${PREFIX}/sbin/netmond
.if !defined(NOPORTDOCS)
	${MKDIR}  ${DOCSDIR}
	${CHMOD} 555 ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README  ${DOCSDIR}/README.ru

	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}/
	${INSTALL_DATA} ${FILESDIR}/README.port.ru ${DOCSDIR}/
	${INSTALL_DATA} ${FILESDIR}/README.port.eng ${DOCSDIR}/README.port
	${INSTALL_DATA} ${FILESDIR}/README.eng ${DOCSDIR}/README
.endif

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
