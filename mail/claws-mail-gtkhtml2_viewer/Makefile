# New ports collection makefile for:	sylpheed-claws-gtkhtml2_viewer
# Date created:	7 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	gtkhtml2_viewer
PORTVERSION=	0.33
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	HTML renderer plugin for claws-mail

LICENSE=	GPLv3

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	claws-mail>=3.8.1:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.8.1:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf
USE_GNOME=	gtk20
USE_ICONV=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
