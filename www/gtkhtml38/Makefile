# New ports collection makefile for:	gtkhtml
# Date created:				2nd June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkhtml
PORTVERSION=	1.1.6
PORTREVISION=	2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.1
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	pspell.15:${PORTSDIR}/textproc/aspell

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier glibwww libghttp libcapplet gal
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-gconf=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

VERSION=	${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/libdata/pkgconfig/soup.pc) || !defined(WITHOUT_SOUP)
LIB_DEPENDS+=	soup.5:${PORTSDIR}/devel/soup
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

post-configure:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%X11BASE%%|${X11BASE}|g ; \
		s|%%VERSION%%|${VERSION}|g' ${FILESDIR}/gtkhtmlConf.sh \
			> ${WRKSRC}/gtkhtmlConf.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/gtkhtmlConf.sh \
		${PREFIX}/etc/gtkhtmlConf.sh

.include <bsd.port.post.mk>
