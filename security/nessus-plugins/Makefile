# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	nessus-plugins
PORTVERSION=	2.2.9
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.ayamura.org/pub/nessus/nessus-${PORTVERSION}/src/
DISTNAME=	nessus-plugins-GPL-${PORTVERSION}
DIST_SUBDIR=	nessus

MAINTAINER=	udo.schweigert@siemens.com
COMMENT=	Plugins for Nessus, the security scanner

BUILD_DEPENDS=	${LOCALBASE}/include/nessus/nessus-devel.h:security/nessus
RUN_DEPENDS=	${LOCALBASE}/include/nessus/nessus-devel.h:security/nessus \
		nmap:security/nmap

DEPRECATED=	Abandoned, consider using OpenVAS
EXPIRATION_DATE=2016-09-30

USES=		libtool
WRKSRC=		${WRKDIR}/nessus-plugins

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fetchcmd=wget --localstatedir="${PREFIX}/var"

post-patch:
	@${REINPLACE_CMD} 's/-o $$(installuser)//' ${WRKSRC}/Makefile

.include <bsd.port.mk>
