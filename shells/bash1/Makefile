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

DEPRECATED=	Bash 1.x is EOL, please use shells/bash.
EXPIRATION_DATE=	2004-08-25

NO_LATEST_LINK=	yes
WRKSRC=	${WRKDIR}/${DISTNAME}
# Don't compress manpages or .so not works.
NOMANCOMPRESS=	yes
MAN1=		bash.1 bash_builtins.1
INFO=		bash

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		"Does not compile on ia64"
.endif

post-install:
	@install-info ${PREFIX}/info/bash.info ${PREFIX}/info/dir

.include <bsd.port.post.mk>
