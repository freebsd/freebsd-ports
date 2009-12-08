# New ports collection makefile for:	adasockets
# Date created:		22 May 2000
# Whom:			sam@inf.enst.fr
#
# $FreeBSD$
#

PORTNAME=		adasockets
PORTVERSION=		1.8.4.7
PORTREVISION=	3
CATEGORIES=		net
MASTER_SITES=		http://www.rfc1149.net/download/adasockets/

MAINTAINER=		john_m_cooper@yahoo.com
COMMENT=		Sockets library for Ada

BUILD_DEPENDS=		gnatmake:${PORTSDIR}/lang/gnat \
			texi2dvi:${PORTSDIR}/print/teTeX

BROKEN=			does not build
DEPRECATED=		has been broken for 3 months
EXPIRATION_DATE=	2010-01-08

USE_AUTOTOOLS=		autoconf:262
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--disable-examples
.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--disable-doc
.endif
USE_LDCONFIG=		yes

MAN1=			adasockets-config.1
INFO=			adasockets

.include <bsd.port.mk>
