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

NO_LATEST_LINK=	yes
WRKSRC=	${WRKDIR}/${DISTNAME}
# Don't compress manpages or .so not works.
NOMANCOMPRESS=	yes
MAN1=		bash.1 bash_builtins.1

post-install:
	@install-info ${PREFIX}/info/bash.info ${PREFIX}/info/dir

.include <bsd.port.mk>
