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

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Prelude Network Intrusion Detection System sensor

LIB_DEPENDS=	prelude.1:${PORTSDIR}/security/libprelude

USE_GMAKE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--with-html-dir=${PREFIX}/share/doc \
			--program-prefix=""

MAN8=			prelude-nids.8

post-patch:
	${CP} ${FILESDIR}/libpcap.diff ${WRKSRC}

.include <bsd.port.mk>
