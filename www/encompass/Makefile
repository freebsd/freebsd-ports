# Ports collection Makefile for:	encompass
# Date created:				26 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	encompass
PORTVERSION=	0.4.5
PORTREVISION=	2
CATEGORIES=	www gnome
MASTER_SITES=	http://elysium.zoned.net/${PORTNAME}/ \
		http://encompass.sourceforge.net/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	msgfmt-old:${PORTSDIR}/devel/gettext-old
LIB_DEPENDS=	neon.22:${PORTSDIR}/www/neon

USE_GNOME=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		MSGFMT="${LOCALBASE}/bin/msgfmt-old" \
		XGETTEXT="${LOCALBASE}/bin/xgettext-old"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
