# New ports collection makefile for:	mail-notification
# Date created:			18 Sep 2003
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		mail-notification
PORTVERSION=		0.5.0
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	mailnotify

MAINTAINER=		jylefort@brutele.be
COMMENT=		A mail notification for freedesktop.org-compliant system trays

USE_X_PREFIX=		yes
USE_GNOME=		gnomeprefix gnomehack eel2
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=		MBOX "mbox support" on \
			MH "MH support" on \
			MAILDIR "Maildir support" on \
			POP3 "POP3 support" on \
			SYLPHEED "Sylpheed support" on \
			GMAIL "Gmail support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MBOX)
CONFIGURE_ARGS+=	--disable-mbox
.endif
.if defined(WITHOUT_MH)
CONFIGURE_ARGS+=	--disable-mh
.endif
.if defined(WITHOUT_MAILDIR)
CONFIGURE_ARGS+=	--disable-maildir
.endif
.if defined(WITHOUT_POP3)
CONFIGURE_ARGS+=	--disable-pop3
.else
LIB_DEPENDS+=		gnet-2.0:${PORTSDIR}/net/gnet2
.endif
.if defined(WITHOUT_SYLPHEED)
CONFIGURE_ARGS+=	--disable-sylpheed
.endif
.if defined(WITHOUT_GMAIL)
CONFIGURE_ARGS+=	--disable-gmail
.else
LIB_DEPENDS+=		soup-2.0:${PORTSDIR}/devel/libsoup
.endif

.include <bsd.port.post.mk>
