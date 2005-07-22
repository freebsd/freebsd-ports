# New ports collection makefile for: sscep
# Date created:        Feb 15 2005
# Whom:                Vsevolod Stakhov
#
# $FreeBSD$
#

PORTNAME=		sscep
PORTVERSION=		20040325
CATEGORIES=		security
MASTER_SITES=		http://www.klake.org/~jt/sscep/
DISTNAME=		${PORTNAME}
EXTRACT_SUFX=		.tgz

MAINTAINER=		vsevolod@FreeBSD.org
COMMENT=		Simple scep client

USE_OPENSSL=		yes

MAKE_ARGS+=	BINDIR="${PREFIX}/bin" \
		CONFDIR="${PREFIX}/etc"

.include <bsd.port.mk>
