# New ports collection makefile for:	mc-light
# Date created:				31.08.2004
# Whom:					Roman Y. Bogdanov <sam@brj.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	mc-light
PORTVERSION=	4.1.40.p9
PORTREVISION=	2
CATEGORIES=	misc shells
MASTER_SITES=	http://mc.linuxinside.com/Releases/
DISTNAME=	mc-${PORTVERSION:S/.p9/-pre9/}

MAINTAINER=	sam@brj.pp.ru
COMMENT=	A lightweight Midnight Commander clone

RUN_DEPENDS+=	gawk:${PORTSDIR}/lang/gawk

CONFLICTS=	mc-4.6*

USE_GMAKE=	yes
USE_ICONV=	yes
USE_GNOME=	pkgconfig gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-included-slang \
		--with-gettext \
		--with-vfs \
		--with-netrc \
		--without-gpm-mouse \
		--with-edit

MAN1=		mc.1 mcedit.1
MAN8=		mcserv.8

.if !defined(WITH_SUBSHELL)
CONFIGURE_ARGS+=--without-subshell
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
.for i in a arfs audio cpio deb esp ftplist hp48 iso lha lslR mailfs patchfs rar rpm trpm uarj uha zip zoo
	${CHMOD} 755 ${PREFIX}/share/mc/extfs/${i}
.endfor

.include <bsd.port.mk>
