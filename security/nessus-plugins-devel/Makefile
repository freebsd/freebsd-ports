# Ports collection makefile for:	nessus-plugins-devel
# Date created:		27 Oct 2001
# Whom:			Udo Schweigert <udo.schweigert@siemens.com>
#
# $FreeBSD$
#

PORTNAME=	nessus-plugins-devel
PORTVERSION=	2.1.2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.au.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.ayamura.org/pub/nessus/nessus-${PORTVERSION}/src/
DISTNAME=	nessus-plugins-${PORTVERSION}

MAINTAINER=	udo.schweigert@siemens.com
COMMENT=	Plugins for Nessus, the security scanner

CONFLICTS=	nessus-plugins-[0-9]*

BUILD_DEPENDS=	${LOCALBASE}/include/nessus/nessus-devel.h:${PORTSDIR}/security/nessus-devel
RUN_DEPENDS=	${LOCALBASE}/include/nessus/nessus-devel.h:${PORTSDIR}/security/nessus-devel \
		nmap:${PORTSDIR}/security/nmap \
		wget:${PORTSDIR}/ftp/wget

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-plugins

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fetchcmd=wget

MAN1=		nessus-build.1
MAN8=		nessus-update-plugins.8

.include <bsd.port.pre.mk>

post-install:
	@${ECHO} "================================================================================"
	@${ECHO} "Use ${PREFIX}/sbin/nessus-update-plugins to update your plugin"
	@${ECHO} "collection."
	@${ECHO} "================================================================================"

.include <bsd.port.post.mk>
