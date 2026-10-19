PORTNAME=	scim
PORTVERSION=	1.4.9
PORTREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Smart Common Input Method platform
WWW=		https://github.com/scim-im/scim

LICENSE=	LGPL21

DEPRECATED=	Abandoned and Unmentenanced, this version is 17 years old and the latest version 1.4.18 is 9 years old
EXPIRATION_DATE=2026-12-31

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		compiler:c++11-lang gettext gmake gnome iconv libtool pathfix \
		pkgconfig xorg
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
