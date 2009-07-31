# New ports collection makefile for:	clearlooks-themes-extras
# Date created:				10 April 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clearlooks-themes-extras
PORTVERSION=	0.6
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	laszlof
DISTNAME=	Clearlooks-Big_Pack-${PORTVERSION}.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extras colour schemes for Clearlooks engine theme

NO_BUILD=	yes
USE_GNOME=	gtk20

THEME_DIR=	${PREFIX}/share/themes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/libdata/pkgconfig/gtk-engines-2.pc) || defined(WITH_GTKENGINE)
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2
.else
RUN_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libclearlooks.so:${PORTSDIR}/x11-themes/clearlooks
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
