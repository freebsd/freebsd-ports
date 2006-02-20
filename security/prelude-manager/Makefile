# New ports collection makefile for:	prelude-manager
# Date created:			Sun Aug 4 19:31:17 CEST 2002
# Whom:				Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	prelude-manager
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.org/download/releases/

MAINTAINER=	r.gruyters@yirdis.nl
COMMENT=	Prelude Network Intrusion Detection System central logging point

LIB_DEPENDS+=	prelude.6:${PORTSDIR}/security/libprelude \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_GPG=	yes
SIG_SUFFIX=	.sig
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15:inc
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--with-html-dir=${PREFIX}/share/doc \
			--localstatedir=/var

.if defined(WITHOUT_DB)
PLIST_SUB+=	WITH_DB="@comment "
.else
LIB_DEPENDS+=	preludedb.2:${PORTSDIR}/security/libpreludedb
PLIST_SUB+=	WITH_DB=""
.endif

.include <bsd.port.mk>
