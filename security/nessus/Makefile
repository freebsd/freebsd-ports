# New ports collection makefile for: 	nessus
# Date created:		1 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	nessus
PORTVERSION=	1.2.4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cis.fed.gov/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://cvs.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.esiea.fr/pub/mirrors/nessus/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.chg.ru/pub/security/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.sekure.net/pub/nessus/nessus-${PORTVERSION}/src/
DISTNAME=	nessus-core-${PORTVERSION}

MAINTAINER=	udo.schweigert@siemens.com

LIB_DEPENDS=	nasl.3:${PORTSDIR}/security/nessus-libnasl

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-core

USE_LIBTOOL=	yes
WANT_GTK=	yes

.include <bsd.port.pre.mk>

.if defined(HAVE_GTK)
USE_GTK=	yes
.else
CONFIGURE_ARGS+=--disable-gtk
.endif

CONFIGURE_ARGS+=	--sharedstatedir=${PREFIX}/etc/nessus/com \
			--localstatedir=${PREFIX}/etc/nessus/var

MAN1=		nessus.1 nessus-mkrand.1 nessus-mkcert-client.1
MAN8=		nessusd.8 nessus-adduser.8 nessus-mkcert.8 nessus-rmuser.8

post-install:
.if ! defined(BATCH)
.if ! exists(${PREFIX}/etc/nessus/var/CA/serverkey.pem)
	${PREFIX}/sbin/nessus-mkcert
.endif
.endif

.include <bsd.port.post.mk>
