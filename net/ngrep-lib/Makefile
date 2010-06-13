# New ports collection makefile for:   ngrep-lib
# Date created:        28 August 2001
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	ngrep-lib
PORTVERSION=	1.3
CATEGORIES=	net
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Easy packet filtering library based on ngrep

MAN3=		ngrep-lib.3
HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=--prefix=${PREFIX} -without-restart

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "amd64"
BROKEN=		Does not compile on ia64 or amd64 (needs -fPIC)
.endif

.include <bsd.port.post.mk>
