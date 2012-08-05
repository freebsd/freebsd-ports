# New ports collection makefile for:	netmond
# Date created:				2004 Mar 30
# Whom:					vfom@narod.ru
#
# $FreeBSD$
#

PORTNAME=	netmond
PORTVERSION=	2.2b6
PORTREVISION=	5
CATEGORIES=	net-mgmt
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		ftp://ftp.risp.ru/pub/RinetSoftware/
DISTNAME=	netmond-2.2-b6
EXTRACT_SUFX=	.tgz

PATCH_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://vfom.narod.ru/download/
PATCH_VERSION=	1
PATCHFILES=	${DISTNAME}.patch${PATCH_VERSION}${EXTRACT_SUFX}  ${DISTNAME}.docs${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Netmond - IP network monitoring daemon

USERS=	netmon
GROUPS=	${USERS}

#MK_IFGRAPH=	yes
PATCHDIR=	${WRKDIR}/patches

.if defined(MK_IFGRAPH)
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
.else
CONFIGURE_ARGS=	--without-ifgraph
.endif

GNU_CONFIGURE=	yes
USE_BISON=	build

BINOWN=		root
BINGRP=		netmon
BINMODE=	0550

PLIST_FILES=	sbin/netmond sbin/netmond_watchdog sbin/netmondctl \
		etc/netmond.conf.sample
.if defined(MK_IFGRAPH)
PLIST_FILES+=	sbin/ifgraph
.endif

USE_RC_SUBR=	netmond

SUB_FILES+=	pkg-message netmond_watchdog netmondctl

PORTDOCS=	README README.ru CHANGES README.port.eng README.port.ru index.html netmond.css en/ ru/

post-extract:
	${MKDIR} ${PATCHDIR}
	${TAR} -zxf ${DISTDIR}/${DISTNAME}.patch${PATCH_VERSION}${EXTRACT_SUFX} -C ${PATCHDIR}
	${CP} ${PATCHDIR}/pipe.c ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netmond      ${PREFIX}/sbin/netmond
.if defined(MK_IFGRAPH)
	${INSTALL_PROGRAM} ${WRKSRC}/ifgraph      ${PREFIX}/sbin/ifgraph
.endif
	${INSTALL_SCRIPT}   ${WRKDIR}/netmond_watchdog ${PREFIX}/sbin/netmond_watchdog
	${INSTALL_SCRIPT}   ${WRKDIR}/netmondctl ${PREFIX}/sbin/netmondctl
	${INSTALL_DATA} ${WRKSRC}/netmon.conf.sample ${PREFIX}/etc/netmond.conf.sample
	${CHMOD} u+s ${PREFIX}/sbin/netmond
.if !defined(NOPORTDOCS)
	${MKDIR}  ${DOCSDIR}
	${CHMOD} 755 ${DOCSDIR}
	${TAR}  -zxf ${DISTDIR}/${DISTNAME}.docs${EXTRACT_SUFX} -C ${DOCSDIR}
.endif

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
