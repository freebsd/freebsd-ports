# New ports collection makefile for: dtse
# Date created: 7 Mar 2004
# Whom: Douglas Thrift <douglas@douglasthrift.net>
#
# $FreeBSD$
#

PORTNAME=	dtse
PORTVERSION=	1.3
CATEGORIES=	www perl5
MASTER_SITES=	http://computers.douglasthrift.net/searchengine/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	An indexing search engine for use on small websites

.if defined(WITH_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.endif

USE_PERL5=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}/${PORTNAME}

MAKEFILE=	GNUmakefile

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
