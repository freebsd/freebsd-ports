# New ports collection makefile for:   barque
# Date created:        28 March 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	barque
PORTVERSION=	0.1.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}-0.1-2.tar.gz

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gtkhtml.8:${PORTSDIR}/www/gtkhtml \
		bonobo.2:${PORTSDIR}/devel/bonobo \
		gconf-1.1:${PORTSDIR}/devel/gconf \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		ghttp.1:${PORTSDIR}/www/libghttp \
		glade.4:${PORTSDIR}/devel/libglade

WRKSRC=		${WRKDIR}/${PORTNAME}-0.1-2

USE_GMAKE=	yes
USE_GNOME=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
