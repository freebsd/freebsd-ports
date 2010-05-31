# New ports collection makefile for:	gtkhtml
# Date created:				2nd June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkhtml
PORTVERSION=	1.1.10
PORTREVISION=	14
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Lightweight HTML rendering/printing/editing engine

LIB_DEPENDS=	pspell.16:${PORTSDIR}/textproc/aspell

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier glibwww libghttp libcapplet gal
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--with-gconf=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

VERSION=	${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/libdata/pkgconfig/soup.pc) || !defined(WITHOUT_SOUP)
LIB_DEPENDS+=	soup.6:${PORTSDIR}/devel/soup
.endif

post-configure:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%VERSION%%|${VERSION}|g' ${FILESDIR}/gtkhtmlConf.sh \
			> ${WRKSRC}/gtkhtmlConf.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/gtkhtmlConf.sh \
		${PREFIX}/etc/gtkhtmlConf.sh

.include <bsd.port.post.mk>
