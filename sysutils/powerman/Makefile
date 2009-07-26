# New ports collection makefile for:	powerman
# Date created:		29 March 2004
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	powerman
PORTVERSION=	2.3.5
CATEGORIES=	sysutils parallel
MASTER_SITES=	SF/powerman

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PowerMan is a tool for doing remote power control

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

USE_PERL5_BUILD=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-httppower --localstatedir=${DESTDIR}/var \
		--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes
USE_RC_SUBR=	powerman.sh

CFLAGS+=	-I${LOCALBASE}/include -DHAVE_CURL
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		pm.1 powerman.1
MAN3=		libpowerman.3
MAN5=		powerman.conf.5 powerman.dev.5
MAN7=		powerman-devices.7
MAN8=		httppower.8 plmpower.8 powermand.8 vpcd.8

.include <bsd.port.mk>
