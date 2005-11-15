# New ports collection makefile for:	prelude-nids
# Date created:			Sun Aug 4 19:31:17 CEST 2002
# Whom:				Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	prelude-nids
PORTVERSION=	0.8.6
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.org/download/releases/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Prelude Network Intrusion Detection System sensor

IGNORE=		is deprecated and does not build with libprelude-0.9.0 or later
DEPRECATED=	Prelude 0.9.0 and later is using Snort as its default NIDS sensor
EXPIRATION_DATE=	2005-11-21

LIB_DEPENDS=	prelude.1:${PORTSDIR}/security/libprelude

USE_GMAKE=		yes
USE_AUTOTOOLS=	libtool:13
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--with-html-dir=${PREFIX}/share/doc

MAN8=			prelude-nids.8

post-patch:
	${CP} ${FILESDIR}/libpcap.diff ${WRKSRC}

.include <bsd.port.mk>
