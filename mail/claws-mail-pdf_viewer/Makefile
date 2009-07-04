# New ports collection makefile for:	claws-mail-pdf_viewer
# Date created:		2007-03-02
# Whom:			Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	pdf_viewer
PORTVERSION=	0.9.1
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-

MAINTAINER=	c0rn@o2.pl
COMMENT=	This claws-mail plugin enables viewing of PDF and PS files

LIB_DEPENDS=	poppler-glib:${PORTSDIR}/graphics/poppler-gtk
BUILD_DEPENDS=	claws-mail>=3.7.2:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.7.2:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_ICONV=	yes
USE_GHOSTSCRIPT=yes
USE_AUTOTOOLS=	autoconf:262
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS=	--with-iconv-prefix=${LOCALBASE} \
	--with-libintl-prefix=${LOCALBASE}

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
