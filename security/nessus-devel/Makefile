# New ports collection makefile for: 	nessus-devel
#
# $FreeBSD$
#

PORTNAME=	nessus-devel
PORTVERSION=	1.3.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.nessus.org/pub/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/unstable/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.chg.ru/pub/security/nessus/unstable/nessus-${PORTVERSION}/src/ \
		ftp://ftp.sekure.net/pub/nessus/unstable/nessus-${PORTVERSION}/src/
DISTNAME=	nessus-core-${PORTVERSION}

MAINTAINER=	udo.schweigert@siemens.com

LIB_DEPENDS=	nasl.4:${PORTSDIR}/security/nessus-libnasl-devel

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-core

USE_LIBTOOL=	yes
USE_GNOMENG=	yes
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
.if ! defined(BATCH)
.if ! exists(${PREFIX}/etc/nessus/var/CA/serverkey.pem)
	${PREFIX}/sbin/nessus-mkcert
.endif
.endif

.include <bsd.port.post.mk>
