# Ports collection makefile for:	nessus-plugins-devel
#
# $FreeBSD$
#

PORTNAME=	nessus-plugins-devel
PORTVERSION=	2.0.10a
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

.if ${ARCH} == "amd64"
PLIST_SUB+=	AMD="@comment "
pre-configure:
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-3com-hub-amd64
.else
PLIST_SUB+=	AMD=""
BUILD_DEPENDS+=	libnet-config:${PORTSDIR}/net/libnet
.endif

post-install:
	@${ECHO} "================================================================================"
	@${ECHO} "Use ${PREFIX}/sbin/nessus-update-plugins to update your plugin"
	@${ECHO} "collection."
	@${ECHO} "================================================================================"

.include <bsd.port.post.mk>
