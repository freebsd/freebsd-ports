# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	nessus
PORTVERSION=	2.2.9
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.ayamura.org/pub/nessus/nessus-${PORTVERSION}/src/
DISTNAME=	nessus-core-${PORTVERSION}
DIST_SUBDIR=	nessus

MAINTAINER=	udo.schweigert@siemens.com
COMMENT=	Security scanner: looks for vulnerabilities in a given network

LICENSE=	GPLv2

LIB_DEPENDS=	libnasl.so:${PORTSDIR}/security/nessus-libnasl

OPTIONS_DEFINE=	GTK2
OPTIONS_DEFAULT=GTK2

GTK2_CONFIGURE_ENABLE=	gtk
GTK2_USES=	pkgconfig
GTK2_USE=	GNOME=gtk20

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
SUB_FILES=	nessusd.conf
USE_RC_SUBR=	nessusd
WRKSRC=		${WRKDIR}/nessus-core

post-install:
	${INSTALL_DATA} ${WRKDIR}/nessusd.conf \
		${STAGEDIR}${ETCDIR}/nessusd.conf.dist
	${INSTALL_DATA} ${FILESDIR}/nessusd.rules \
		${STAGEDIR}${ETCDIR}/nessusd.rules.dist

.include <bsd.port.mk>
