# Created by: Jie Gao	<gaoj@cpsc.ucalgary.ca>
# $FreeBSD$

PORTNAME=	scim
PORTVERSION=	1.4.9
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Smart Common Input Method platform

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		compiler:c++11-lang gettext gmake gnome iconv libtool pathfix \
		pkgconfig
USE_GNOME=	gtk20 intlhack
USE_XORG=	x11 xpm
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LIBS+=		-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} 's/-lstdc++//'				\
		${WRKSRC}/extras/gtk2_immodule/Makefile.in		\
		${WRKSRC}/extras/setup/Makefile.in			\
		${WRKSRC}/src/Makefile.in				\
		${WRKSRC}/tests/Makefile.in

.include <bsd.port.mk>
