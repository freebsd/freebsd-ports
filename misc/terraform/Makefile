# ex:ts=8
# Ports collection makefile for:	terraform
# Date created:			Feb 8, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	terraform
PORTVERSION=	0.9.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive height field generation and manipulation program

BUILD_DEPENDS=	${LOCALBASE}/lib/libtrio.a:${PORTSDIR}/devel/trio
LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		intl.4:${PORTSDIR}/devel/gettext \
		png.5:${PORTSDIR}/graphics/png \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		xml.5:${PORTSDIR}/textproc/libxml

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_BISON=	yes
USE_GNOME=	gtk12 gdkpixbuf orbit gnomelibs gnomeprint
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|Bison |Bison|; \
		s|-ltrio  $$LIBS|-ltrio -lm $$LIBS|" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|malloc\.h|stdlib.h|" ${WRKSRC}/src/xmlsupport.c

.include <bsd.port.mk>
