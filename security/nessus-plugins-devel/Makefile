# Ports collection makefile for:	nessus-plugins-devel
#
# $FreeBSD$
#

PORTNAME=	nessus-plugins-devel
PORTVERSION=	1.1.12
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cis.fed.gov/pub/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.nessus.org/pub/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://cvs.nessus.org/pub/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/unstable/nessus/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.esiea.fr/pub/mirrors/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.chg.ru/pub/security/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.sekure.net/pub/nessus/unstable/nessus-${PORTVERSION}/src/

MAINTAINER=	udo.schweigert@siemens.com

BUILD_DEPENDS=	${LOCALBASE}/include/nessus/nessus-devel.h:${PORTSDIR}/security/nessus-devel \
		${LOCALBASE}/bin/nmap:${PORTSDIR}/security/nmap \
		${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget
RUN_DEPENDS=	nmap:${PORTSDIR}/security/nmap

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-plugins
DISTNAME=	nessus-plugins-${PORTVERSION}

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
