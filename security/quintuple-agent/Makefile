# New ports collection makefile for:	quintuple-agent
# Date created:			2003-02-06
# Whom:				Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	quintuple-agent
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.vibe.at/tools/q-agent/

MAINTAINER=	stolz@i2.informatik.rwth-aachen.de
COMMENT=	Quintuple Agent is a program that stores secrets for you

LIB_DEPENDS+=	intl.5:${PORTSDIR}/devel/gettext-old

USE_GNOME=	glib12
.ifndef(WITHOUT_X11)
USE_GNOME+=	gtk12
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"
#catgets disabled because it can't find all messages:
#CONFIGURE_ARGS+=--with-catgets
.ifdef(WITHOUT_X11)
CONFIGURE_ARGS+=--disable-gtktest
.endif

MAN1=	agpg.1 apgp.1 q-agent.1 secret-ask.1 q-client.1 secret-query.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
