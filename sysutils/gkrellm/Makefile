# New ports collection makefile for:	gkrellm
# Version required:	0.9.6
# Date Created:		Mar 4 2000
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	gkrellm-0.9.6
CATEGORIES=	sysutils ipv6
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/ \
		http://people.FreeBSD.org/~ume/gkrellm/

MAINTAINER=	ume@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

DOCS=		COPYRIGHT README Themes

# You should aware that GKrellM must be setuid root to obtain
# temperatures.  If your motherboard doesn't support LM78/79 feature,
# you may not want this.
USE_SENSOR?=	YES

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
ALL_TARGET=	freebsd2
.else
ALL_TARGET=	freebsd3
.endif

BINGRP=		kmem
.if defined(USE_SENSOR) && ${USE_SENSOR} == YES
BINOWN=		root
BINMODE=	4111
.else
BINMODE=	2111
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gkrellm ${PREFIX}/bin/gkrellm
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gkrellm
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gkrellm
.endfor
.endif
.if defined(USE_SENSOR) && ${USE_SENSOR} == YES
	@${CAT} ${PKGDIR}/MESSAGE
.endif

.include <bsd.port.post.mk>
