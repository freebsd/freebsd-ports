# $FreeBSD$

PORTNAME=	scim-bridge
PORTVERSION=	0.4.16
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Scim-bridge agent (server)

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/doc/LICENSE.GPL
LICENSE_FILE_LGPL21=	${WRKSRC}/doc/LICENSE.LGPL

LIB_DEPENDS=	libscim-1.0.so:textproc/scim

USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
CXXFLAGS+=	${CPPFLAGS}

CONFIGURE_ARGS+=--with-libintl-prefix=${LOCALBASE} \
		--enable-agent \
		--disable-gtk2-immodule \
		--disable-qt3-immodule \
		--disable-qt4-immodule

PLIST_FILES=	bin/scim-bridge

post-patch:
	@${GREP} -lR "<malloc\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'
	@${GREP} -lR "<alloca\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<alloca\.h>|<stdlib.h>|g'

.include <bsd.port.mk>
