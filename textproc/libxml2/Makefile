# New ports collection makefile for:	libxml2
# Date created:				28 September 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	libxml2
PORTVERSION=	2.3.0
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/libxml

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	iconv.2:${PORTSDIR}/converters/iconv

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS=	--with-iconv
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -liconv"

MAN1=		xml2-config.1 xmllint.1
MAN4=		libxml.4

#pre-patch:
#	@find ${WRKSRC}/include -type f -name "*.h" | \
#		xargs ${PERL} -pi -e 's|libxml/|libxml2/|'
#	@${LN} -sf ${WRKSRC}/include/libxml ${WRKSRC}/include/libxml2

.include <bsd.port.mk>
