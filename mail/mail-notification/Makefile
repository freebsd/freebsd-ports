# New ports collection makefile for:	mail-notification
# Date created:			18 Sep 2003
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		mail-notification
PORTVERSION=		0.3.2
CATEGORIES=		mail
MASTER_SITES=		http://streamtuner.sourceforge.net/mail-notification/

MAINTAINER=		jylefort@brutele.be
COMMENT=		A mail notification for the GNOME 2.0 system tray

USE_X_PREFIX=		yes
USE_GNOME=		gnomeprefix gnomehack libgnomeui
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

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

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "	WITHOUT_MBOX=yes	Disable mbox support"
	@${ECHO} "	WITHOUT_MH=yes		Disable MH support"
	@${ECHO} "	WITHOUT_MAILDIR=yes	Disable Maildir support"
	@${ECHO} "	WITHOUT_POP3=yes	Disable POP3 support"
	@${ECHO} "	WITHOUT_SYLPHEED=yes	Disable Sylpheed support"
	@${ECHO} ""

.include <bsd.port.post.mk>
