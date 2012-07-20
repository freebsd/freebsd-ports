# New ports collection makefile for:   grap
# Date created:        4 February 2000
# Whom:                faber@lunabase.org
#
# $FreeBSD$
#

PORTNAME=	grap
PORTVERSION=	1.44
CATEGORIES=	textproc graphics
MASTER_SITES=	http://www.lunabase.org/~faber/Vault/software/grap/

MAINTAINER=	faber@lunabase.org
COMMENT=	An implementation of Kernigan & Bentley's grap language

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--with-freebsd-ports

CONFLICTS_INSTALL=heirloom-doctools-[0-9]*

MAN1=		grap.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${RM} -rf ${DOCSDIR}
.endif

.include <bsd.port.mk>
