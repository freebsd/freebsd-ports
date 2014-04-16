# Created by: Sverrir Valgeirsson <e96sv@yahoo.se>
# $FreeBSD$

PORTNAME=	valknut
PORTVERSION=	0.4.9
PORTREVISION=	6
CATEGORIES=	net-p2p
MASTER_SITES=	SF/wxdcgui/${PORTNAME}-qt4/${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Qt-based Direct Connect client

LICENSE=	GPLv2

LIB_DEPENDS=	libdc.so:${PORTSDIR}/net-p2p/dclib \
		libxml2.so:${PORTSDIR}/textproc/libxml2

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_QT4=	corelib gui network qt3support \
		moc_build uic_build rcc_build linguist_build
USE_BZIP2=	yes
USES=		gmake perl5 pkgconfig
USE_PERL5=	build
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CFLAGS+=	-I${QT_INCDIR}
LDFLAGS+=	-L${QT_LIBDIR}
QTCFGLIBS+=	${PTHREAD_LIBS}
CONFIGURE_ENV+=	DCLIB_CFLAGS=-I${LOCALBASE}/include

post-patch:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g;\
	    s|-D_XOPEN_SOURCE=500||g' \
	    ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
