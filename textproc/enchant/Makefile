# New ports collection makefile for:	enchant
# Date created:				03 January 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	enchant
PORTVERSION=	1.1.2
PORTREVISION=	3
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	abiword
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Dictionary/spellchecking framework

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget glib20
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		enchant.1

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libpspell.so)
WITH_ASPELL=	yes
.endif

.if exists(${LOCALBASE}/bin/ispell)
WITH_ISPELL=	yes
.endif

.if exists(${LOCALBASE}/bin/hspell)
WITH_HSPELL=	yes
.endif

.if defined(WITH_ASPELL)
LIB_DEPENDS+=	pspell.15:${PORTSDIR}/textproc/aspell
PLIST_SUB+=	ASPELL=""
.else
PLIST_SUB+=	ASPELL="@comment "
.endif

.if defined(WITH_ISPELL)
BUILD_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
PLIST_SUB+=	ISPELL=""
.else
PLIST_SUB+=	ISPELL="@comment "
.endif

.if defined(WITH_HSPELL)
BUILD_DEPENDS+=	hspell:${PORTSDIR}/hebrew/hspell
PLIST_SUB+=	HSPELL=""
.else
PLIST_SUB+=	HSPELL="@comment "
.endif

pre-everything::
.if !defined(WITH_ASPELL) || !defined(WITH_ISPELL) || !defined(WITH_HSPELL)
	@${ECHO_CMD} '===> The following options are available for this port:'
.if !defined(WITH_ASPELL)
	@${ECHO_CMD} '===>'
	@${ECHO_CMD} '===> Define WITH_ASPELL to enable aspell support'
.endif
.if !defined(WITH_ISPELL)
	@${ECHO_CMD} '===>'
	@${ECHO_CMD} '===> Define WITH_ISPELL to enable ispell support'
.endif
.if !defined(WITH_HSPELL)
	@${ECHO_CMD} '===>'
	@${ECHO_CMD} '===> Define WITH_HSPELL to enable hspell (Hebrew) support'
.endif
.endif

.include <bsd.port.post.mk>
