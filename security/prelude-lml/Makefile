# New ports collection makefile for:	prelude-lml
# Date created:			Sun Aug 4 19:31:17 CEST 2002
# Whom:				Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	prelude-lml
PORTVERSION=	0.9.4
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.org/download/releases/ \
		http://www.prelude-ids.org/download/releases/old/

MAINTAINER=	r.gruyters@yirdis.nl
COMMENT=	Prelude Network Intrusion Detection System Log Monitoring Lackey

LIB_DEPENDS+=	prelude.[6-?]:${PORTSDIR}/security/libprelude \
		pcre.0:${PORTSDIR}/devel/pcre

USE_GPG=	yes
SIG_SUFFIX=	.sig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	prelude-lml.sh
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

.include <bsd.port.mk>
