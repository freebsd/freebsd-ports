# New ports collection makefile for:   grap
# Date created:        4 February 2000
# Whom:                faber@lunabase.org
#
# $FreeBSD$
#

PORTNAME=	grap
PORTVERSION=	1.22
CATEGORIES=	textproc graphics
MASTER_SITES=	http://www.lunabase.org/~faber/Vault/software/grap/

MAINTAINER=	faber@lunabase.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--with-freebsd-ports

MAN1=		grap.1

post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && make install-docs
.endif

.include <bsd.port.mk>
