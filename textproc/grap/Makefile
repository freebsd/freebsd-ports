# New ports collection makefile for:   grap
# Date created:        4 February 2000
# Whom:                faber@lunabase.org
#
# $FreeBSD$
#

PORTNAME=	grap
PORTVERSION=	1.36
CATEGORIES=	textproc graphics
MASTER_SITES=	http://www.lunabase.org/~faber/Vault/software/grap/

MAINTAINER=	faber@lunabase.org
COMMENT=	An implementation of Kernigan & Bentley's grap language

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--with-freebsd-ports

MAN1=		grap.1

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${MAKE} install-docs
.endif

.include <bsd.port.post.mk>
