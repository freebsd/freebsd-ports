# New ports collection makefile for:	claws-mail-python
# Date created:		27 November 2009
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	python
PORTVERSION=	0.9
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	python_plugin-${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Python plugin for claws-mail

LICENSE=	GPLv3

BUILD_DEPENDS=	claws-mail>=3.8.0:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.8.0:${PORTSDIR}/mail/claws-mail

USE_GNOME=	pygtk2
USE_GMAKE=	yes
USE_XORG=	x11
USE_AUTOTOOLS=	autoconf
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
