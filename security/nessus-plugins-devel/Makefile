# Ports collection makefile for:	nessus-plugins-devel
#
# $FreeBSD$
#

PORTNAME=	nessus-plugins-devel
PORTVERSION=	1.3.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.nessus.org/pub/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/unstable/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.chg.ru/pub/security/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.sekure.net/pub/nessus/unstable/nessus-${PORTVERSION}/src/
DISTNAME=	nessus-plugins-${PORTVERSION}

MAINTAINER=	udo.schweigert@siemens.com

BUILD_DEPENDS=	${LOCALBASE}/include/nessus/nessus-devel.h:${PORTSDIR}/security/nessus-devel \
		libnet-config:${PORTSDIR}/net/libnet
RUN_DEPENDS=	${LOCALBASE}/include/nessus/nessus-devel.h:${PORTSDIR}/security/nessus-devel \
		nmap:${PORTSDIR}/security/nmap \
		wget:${PORTSDIR}/ftp/wget

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-plugins

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fetchcmd=wget --sharedstatedir=${PREFIX}/etc/nessus/com \
		--localstatedir=${PREFIX}/etc/nessus/var

MAN1=		nessus-build.1
MAN8=		nessus-update-plugins.8

.include <bsd.port.pre.mk>

post-install:
	@${ECHO} "================================================================================"
	@${ECHO} "Use ${PREFIX}/sbin/nessus-update-plugins to update your plugin"
	@${ECHO} "collection."
	@${ECHO} "================================================================================"

.include <bsd.port.post.mk>
