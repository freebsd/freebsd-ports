# New ports collection makefile for: sscep
# Date created:        Feb 15 2005
# Whom:                Vsevolod Stakhov
#
# $FreeBSD$
#

PORTNAME=		sscep
PORTVERSION=		20071227
CATEGORIES=		security
MASTER_SITES=		http://www.klake.org/~jt/sscep/
DISTNAME=		${PORTNAME}
EXTRACT_SUFX=		.tgz

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Simple scep client
MAKEFILE=		${FILESDIR}/BSDmakefile
ALL_TARGET=		-j`${SYSCTL} -n hw.ncpu`

USE_OPENSSL=		yes

.include <bsd.port.mk>
