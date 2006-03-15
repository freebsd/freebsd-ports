# New ports collection makefile for:	enchant
# Date created:				03 January 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/textproc/enchant/Makefile,v 1.1 2006/03/12 02:08:58 mezz Exp $
#

PORTNAME=	enchant
PORTVERSION=	1.2.3
CATEGORIES=	textproc gnome
MASTER_SITES=	http://www.abisource.com/downloads/enchant/${PORTVERSION}/
#		${MASTER_SITE_SOURCEFORGE}
#MASTER_SITE_SUBDIR=	abiword
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Dictionary/spellchecking framework

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack gnometarget glib20 ltverhack
CONFIGURE_ARGS=	--disable-hspell \
		--disable-uspell
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		enchant.1

.ifndef(WITHOUT_ASPELL)
LIB_DEPENDS+=	pspell.16:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=--enable-aspell
PLIST_SUB+=	ASPELL=""
.else
CONFIGURE_ARGS+=--disable-aspell
PLIST_SUB+=	ASPELL="@comment "
.endif

.include <bsd.port.pre.mk>

#.if exists(${LOCALBASE}/bin/hspell)
#WITH_HSPELL=	yes
#.endif

#.if defined(WITH_HSPELL)
#BUILD_DEPENDS+=	hspell:${PORTSDIR}/hebrew/hspell
#CONFIGURE_ARGS+=--enable-hspell
#PLIST_SUB+=	HSPELL=""
#.else
#CONFIGURE_ARGS+=--disable-hspell
#PLIST_SUB+=	HSPELL="@comment "
#.endif

pre-everything::
.if !defined(WITHOUT_ASPELL) || !defined(WITH_HSPELL)
	@${ECHO_CMD} '===> The following options are available for this port:'
.if !defined(WITHOUT_ASPELL)
	@${ECHO_CMD} '===>'
	@${ECHO_CMD} '===> Define WITHOUT_ASPELL to disable aspell support'
.endif
#.if !defined(WITH_HSPELL)
#	@${ECHO_CMD} '===>'
#	@${ECHO_CMD} '===> Define WITH_HSPELL to enable hspell (Hebrew) support'
#.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|MKDIRPROG-mkdir|MKDIRPROG-mkdir -p|g' \
		${WRKSRC}/install-sh

.include <bsd.port.post.mk>
