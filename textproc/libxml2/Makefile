# New ports collection makefile for:	libxml2
# Date created:				28 September 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	libxml2
PORTVERSION=	2.4.12
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/libxml

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	giconv.2:${PORTSDIR}/converters/libiconv
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS=	--with-iconv=${LOCALBASE} \
		--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		xml2-config.1 xmllint.1 xmlcatalog.1
MAN4=		libxml.4

pre-patch:
	@find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		's|\$\(libdir\)/pkgconfig|\$\(prefix\)/libdata/pkgconfig|g'
	@cd ${WRKSRC} && ${PERL} -pi -e \
		's|([^g])iconv.h|\1giconv.h|g ; s|-liconv|-lgiconv|g' \
			configure include/libxml/encoding.h

.include <bsd.port.mk>
