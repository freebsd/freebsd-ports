# Created by: Sverrir Valgeirsson <e96sv@yahoo.se>
# $FreeBSD$

PORTNAME=	valknut
PORTVERSION=	0.4.9
PORTREVISION=	6
CATEGORIES=	net-p2p
MASTER_SITES=	SF/wxdcgui/${PORTNAME}-qt4/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt-based Direct Connect client

LICENSE=	GPLv2

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libdc.so:net-p2p/dclib \
		libxml2.so:textproc/libxml2

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_QT=		corelib gui network qt3support \
		moc_build uic_build rcc_build linguisttools_build
USES=		gmake perl5 pkgconfig qt:4 tar:bzip2
USE_PERL5=	build
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CFLAGS+=	-I${QT_INCDIR}
LDFLAGS+=	-L${QT_LIBDIR}
QTCFGLIBS+=	-lpthread
CONFIGURE_ENV+=	DCLIB_CFLAGS=-I${LOCALBASE}/include

post-patch:
	${REINPLACE_CMD} -e 's|-D_XOPEN_SOURCE=500||g' \
	    ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
