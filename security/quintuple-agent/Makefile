# New ports collection makefile for:	quintuple-agent
# Date created:			2003-02-06
# Whom:				Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	quintuple-agent
PORTVERSION=	1.0.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	vs@FreeBSD.org
COMMENT=	Quintuple Agent is a program that stores secrets for you

USE_GETTEXT=	yes
USE_GETOPT_LONG=yes
USE_GNOME=	glib12
.ifndef(WITHOUT_X11)
USE_GNOME+=	gtk12
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"
#catgets disabled because it can't find all messages:
#CONFIGURE_ARGS+=--with-catgets
.ifdef(WITHOUT_X11)
CONFIGURE_ARGS+=--disable-gtktest
.endif
USE_GMAKE=	yes
MAKE_ARGS=	SUBDIRS="doc intl lib m4 po . test"

MAN1=	agpg.1 apgp.1 q-agent.1 secret-ask.1 q-client.1 secret-query.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
