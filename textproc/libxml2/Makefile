# New ports collection makefile for:	libxml2
# Date created:				28 September 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	libxml2
PORTVERSION=	2.4.1
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/libxml

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	giconv.2:${PORTSDIR}/converters/libiconv
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS=	--with-iconv \
		--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgiconv"

MAN1=		xml2-config.1 xmllint.1
MAN4=		libxml.4

pre-patch:
	@find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		's|\$\(libdir\)/pkgconfig|\$\(prefix\)/libdata/pkgconfig|g'

.include <bsd.port.mk>
