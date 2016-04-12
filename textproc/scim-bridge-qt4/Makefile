# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	scim-bridge
PORTVERSION=	0.4.16
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION}
PKGNAMESUFFIX=	-qt4

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Qt4 client for Scim-bridge

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/doc/LICENSE.GPL
LICENSE_FILE_LGPL21=	${WRKSRC}/doc/LICENSE.LGPL

RUN_DEPENDS=	scim-bridge:textproc/scim-bridge

USE_QT4=	corelib gui moc_build
QT_NONSTANDARD=	yes
USES=		gettext gmake libtool pkgconfig
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
CXXFLAGS+=	${CPPFLAGS}

CONFIGURE_ARGS+=--with-libintl-prefix=${LOCALBASE} \
		--disable-agent \
		--disable-gtk2-immodule \
		--disable-qt3-immodule \
		--enable-qt4-immodule

post-patch:
	@${GREP} -lR "<malloc\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'
	@${GREP} -lR "<alloca\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<alloca\.h>|<stdlib.h>|g'
	@${REINPLACE_CMD} -e '/^MOC/s|=.*|=${MOC}|' \
		-e '/^moduledir/s|=.*|=${PREFIX}/lib/qt4/plugins/inputmethods|' \
		${WRKSRC}/client-qt/qt4/Makefile.in

.include <bsd.port.mk>
