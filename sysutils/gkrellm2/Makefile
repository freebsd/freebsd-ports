# New ports collection makefile for:	gkrellm
# Date Created:		Mar 4 2000
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellm
PORTVERSION= 	0.9.8
CATEGORIES=	sysutils ipv6
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/ \
		http://people.FreeBSD.org/~ume/gkrellm/

MAINTAINER=	ume@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		gdk_imlib.5:${PORTSDIR}/graphics/imlib

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

INCLUDES=	gkrellm.h gkrellm_public_proto.h gkrellm_private_proto.h
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

post-patch:
	@${MV} ${WRKSRC}/gkrellm.h ${WRKSRC}/gkrellm.h.orig
	@${SED} -e "s^/usr/share/^${PREFIX}/share/^" \
		${WRKSRC}/gkrellm.h.orig > ${WRKSRC}/gkrellm.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gkrellm ${PREFIX}/bin/gkrellm
	@${MKDIR} ${PREFIX}/include/gkrellm
.for file in ${INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include/gkrellm
.endfor
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
