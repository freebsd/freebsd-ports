# New ports collection makefile for:	gkrellm
# Date Created:		Mar 4 2000
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellm
PORTVERSION=	0.10.3
CATEGORIES=	sysutils ipv6
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ume

MAINTAINER=	ume@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		gdk_imlib.5:${PORTSDIR}/graphics/imlib

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

INCLUDES=	gkrellm.h gkrellm_public_proto.h gkrellm_private_proto.h
DOCS=		COPYRIGHT README Themes.html

# You should aware that GKrellM must be setuid root to obtain
# temperatures.  If your motherboard doesn't support LM78/79 feature,
# you may not want this build WITHOUT_SENSOR=yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
ALL_TARGET=	freebsd2
.elif ${OSVERSION} < 400000
ALL_TARGET=	freebsd3
.else
ALL_TARGET=	freebsd
.endif

BINGRP=		kmem
.if !defined(WITHOUT_SENSOR)
BINOWN=		root
BINMODE=	4111
.else
BINMODE=	2111
.endif

post-patch:
	@${MV} ${WRKSRC}/src/gkrellm.h ${WRKSRC}/src/gkrellm.h.orig
	@${SED} \
	-e "s^/usr/share/gkrellm/themes^${PREFIX}/share/gkrellm/themes^" \
	-e "s^/usr/share/gkrellm/plugins^${PREFIX}/libexec/gkrellm/plugins^" \
		${WRKSRC}/src/gkrellm.h.orig > ${WRKSRC}/src/gkrellm.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gkrellm ${PREFIX}/bin/gkrellm
	@${MKDIR} ${PREFIX}/include/gkrellm
.for file in ${INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/src/${file} ${PREFIX}/include/gkrellm
.endfor
	@${MKDIR} ${PREFIX}/libexec/gkrellm/plugins
	@${MKDIR} ${PREFIX}/share/gkrellm/themes
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gkrellm
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gkrellm
.endfor
.endif
.if !defined(WITHOUT_SENSOR)
	@${CAT} ${PKGDIR}/MESSAGE
.endif

.include <bsd.port.post.mk>
