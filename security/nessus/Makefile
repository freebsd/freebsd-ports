# New ports collection makefile for: 	nessus
# Date created:		1 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	nessus
PORTVERSION=	2.0.10a
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.au.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.ayamura.org/pub/nessus/nessus-${PORTVERSION}/src/
DISTNAME=	nessus-core-${PORTVERSION}

MAINTAINER=	udo.schweigert@siemens.com
COMMENT=	A security scanner: looks for vulnerabilities in a given network

LIB_DEPENDS=	nasl.2:${PORTSDIR}/security/nessus-libnasl

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-core

USE_LIBTOOL=	yes
WANT_GNOME=	yes

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME+=	gtk12
PKGNAMESUFFIX=	-gtk
.else
CONFIGURE_ARGS+=--disable-gtk
.endif

CONFIGURE_ARGS+=	--sharedstatedir=${PREFIX}/etc/nessus/com \
			--localstatedir=${PREFIX}/etc/nessus/var

MAN1=		nessus.1 nessus-mkrand.1 nessus-mkcert-client.1
MAN8=		nessusd.8 nessus-adduser.8 nessus-mkcert.8 nessus-rmuser.8

post-install:
.if ! exists(${PREFIX}/etc/nessus/var/CA/serverkey.pem)
.if ! defined(BATCH)
	${PREFIX}/sbin/nessus-mkcert
.else
	${PREFIX}/sbin/nessus-mkcert -q
.endif
.endif 

.include <bsd.port.post.mk>
