# New ports collection makefile for:	gnomespell
# Date created:				29 December 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomespell
PORTVERSION=	0.4
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/gnome-spell
DISTNAME=	gnome-spell-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/share/xml-i18n-tools/xml-i18n-extract.in:${PORTSDIR}/textproc/xml-i18n-tools
LIB_DEPENDS=	aspell.11:${PORTSDIR}/textproc/aspell

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-extract:
.for file in xml-i18n-extract.in xml-i18n-merge.in xml-i18n-update.in
	@${LN} -sf ${LOCALBASE}/share/xml-i18n-tools/${file} ${WRKSRC}/${file}
.endfor

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
