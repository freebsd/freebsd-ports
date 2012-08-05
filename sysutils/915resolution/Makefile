# New ports collection makefile for:	915resolution
# Date created:				30 Apr 2004
# Whom:					Remington Lang <MrL0Lz@gmail.com>
#
# $FreeBSD$

PORTNAME=	915resolution
PORTVERSION=	0.5.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ehaupt

MAINTAINER=	bahamasfranks@gmail.com
COMMENT=	Resolution tool for Intel i915 video cards

USE_RC_SUBR=	915resolution

DOCS=		README.txt LICENSE.txt chipset_info.txt changes.log

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} 915resolution.c -o 915resolution

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/915resolution ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
