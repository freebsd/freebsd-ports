# New ports collection makefile for:	gkrellm
# Date Created:		Mar 4 2000
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellm
PORTVERSION=	1.2.13
PORTREVISION=	3
CATEGORIES=	sysutils ipv6
MASTER_SITES=	http://members.dslextreme.com/users/billw/gkrellm/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ume

MAINTAINER=	ume@FreeBSD.org
COMMENT=	A GTK based system monitor

CONFLICTS=	gkrellm-2.*

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	imlib
USE_GETTEXT=	yes
USE_GMAKE=	yes

INCLUDES=	gkrellm.h gkrellm_public_proto.h
MAN1=		gkrellm.1

.if !defined(NOPORTDOCS)
PORTDOCS=	COPYRIGHT README Themes.html
.endif

# If you want to support LM78/79 feature, set this to `yes'.  You
# should aware that GKrellM must be setuid root to obtain
# temperatures.  Furthermore, this causes problem on some
# motherboards.  If your motherboard doesn't support LM78/79 feature,
# you should not enable this.
# WITH_SENSOR=yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
ALL_TARGET=	freebsd2
.else
ALL_TARGET=	freebsd
.endif

BINGRP=		kmem
.if defined(WITH_SENSOR)
BINOWN=		root
BINMODE=	4511
.else
BINMODE=	2511
.endif

MAKE_ENV+=	LOCALEDIR=${PREFIX}/share/locale
CFLAGS+=	-DSYSTEM_THEMES_DIR='\"${PREFIX}/share/gkrellm/themes\"' \
		-DSYSTEM_PLUGINS_DIR='\"${PREFIX}/libexec/gkrellm/plugins\"'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gkrellm ${PREFIX}/bin/gkrellm
	@cd ${WRKSRC}/po && \
		${GMAKE} install enable_nls=1 LOCALEDIR=${PREFIX}/share/locale

	@${MKDIR} ${PREFIX}/include/gkrellm
.for f in ${INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/src/${f} ${PREFIX}/include/gkrellm
.endfor
	@${MKDIR} ${PREFIX}/libexec/gkrellm/plugins
	@${MKDIR} ${PREFIX}/share/gkrellm/themes
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${f} ${MANPREFIX}/man/man1/${f}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
.if !defined(WITH_SENSOR)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
