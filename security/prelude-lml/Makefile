# New ports collection makefile for:	prelude-lml
# Date created:			Sun Aug 4 19:31:17 CEST 2002
# Whom:				Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	prelude-lml
PORTVERSION=	0.9.2
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.org/download/releases/

MAINTAINER=	r.gruyters@yirdis.nl
COMMENT=	Prelude Network Intrusion Detection System Log Monitoring Lackey

LIB_DEPENDS+=	prelude.6:${PORTSDIR}/security/libprelude \
		pcre.0:${PORTSDIR}/devel/pcre

USE_GPG=	yes
SIG_SUFFIX=	.sig
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

.include <bsd.port.mk>
