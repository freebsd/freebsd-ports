# ex:ts=8
# Ports collection makefile for:  bash
# Date created:			  21 August 1994
# Whom:				  jkh
#
# $FreeBSD$
#

PORTNAME=	bash
PORTVERSION=	1.14.7
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	bash

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GNU Bourne Again Shell -- old version

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} != i386
BROKEN=		"does not compile on ${MACHINE_ARCH}"
.endif

NO_LATEST_LINK=	yes
WRKSRC=	${WRKDIR}/${DISTNAME}
# Don't compress manpages or .so not works.
NOMANCOMPRESS=	yes
MAN1=		bash.1 bash_builtins.1
INFO=		bash

post-install:
	@install-info ${PREFIX}/info/bash.info ${PREFIX}/info/dir

.include <bsd.port.post.mk>
