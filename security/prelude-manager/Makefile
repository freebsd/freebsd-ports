# New ports collection makefile for:	prelude-manager
# Date created:			Sun Aug 4 19:31:17 CEST 2002
# Whom:				Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	prelude-manager
PORTVERSION=	0.9.3
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.org/download/releases/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Prelude Network Intrusion Detection System central logging point

LIB_DEPENDS+=	prelude.6:${PORTSDIR}/security/libprelude \
		preludedb.2:${PORTSDIR}/security/libpreludedb \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_GPG=	yes
SIG_SUFFIX=	.sig
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--with-html-dir=${PREFIX}/share/doc \
			--localstatedir=/var

.include <bsd.port.mk>
