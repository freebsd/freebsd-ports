# New ports collection makefile for:	clearlooks-themes-extras
# Date created:				10 April 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clearlooks-themes-extras
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.kernow-webhosting.com/~bvc/theme/gtk/clearlooks/
DISTNAME=	Clearlooks-Big_Pack-${PORTVERSION}.x

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	Extras colour schemes for Clearlooks engine theme

NO_BUILD=	yes
USE_X_PREFIX=	yes

THEME_DIR=	${PREFIX}/share/themes

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/libdata/pkgconfig/gtk-engines-2.pc) || defined(WITH_GTKENGINE)
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2
.else
RUN_DEPENDS=	${X11BASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libclearlooks.so:${PORTSDIR}/x11-themes/clearlooks
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@(cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DISTFILES} ${EXTRACT_AFTER_ARGS})

do-install:
	@${MKDIR} ${THEME_DIR}
	@cd ${WRKSRC} && ${FIND} . -print | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${THEME_DIR}

.include <bsd.port.post.mk>
