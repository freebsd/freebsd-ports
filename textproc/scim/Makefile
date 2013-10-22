# Created by: Jie Gao	<gaoj@cpsc.ucalgary.ca>
# $FreeBSD$

PORTNAME=	scim
PORTVERSION=	1.4.9
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Smart Common Input Method platform

LICENSE=	LGPL21

USE_GNOME=	gnomehier gtk20 intlhack
USE_XORG=	x11 xpm
USE_LDCONFIG=	yes
USES=		gettext gmake iconv pathfix pkgconfig
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib -lintl ${ICONV_LIB}

post-patch:
	@${REINPLACE_CMD} 's/-lstdc++//'				\
		${WRKSRC}/extras/gtk2_immodule/Makefile.in		\
		${WRKSRC}/extras/setup/Makefile.in			\
		${WRKSRC}/src/Makefile.in				\
		${WRKSRC}/tests/Makefile.in

.include <bsd.port.mk>
