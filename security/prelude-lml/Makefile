# New ports collection makefile for:	prelude-lml
# Date created:			Sun Aug 4 19:31:17 CEST 2002
# Whom:				Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	prelude-lml
PORTVERSION=	0.8.6
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.org/download/releases/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Prelude Network Intrusion Detection System Log Monitoring Lackey

LIB_DEPENDS+=	prelude.1:${PORTSDIR}/security/libprelude \
		pcre.0:${PORTSDIR}/devel/pcre

USE_GMAKE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc \
			--program-prefix=""

.include <bsd.port.mk>
