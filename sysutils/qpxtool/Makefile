# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	qpxtool
PORTVERSION=	0.7.2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION:C/\.[^.]*$/.x/}/${DISTVERSION}

MAINTAINER=	horia@racoviceanu.com
COMMENT=	GUI for testing CD/DVD quality and transfer rate

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USES=		gmake
USE_QT4=	qmake_build moc_build rcc_build linguist_build corelib gui network sql
QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX=${PREFIX}
USE_LDCONFIG=	yes

post-configure:
	@${REINPLACE_CMD} -e 's|$$(QMAKE4)|& ${QMAKE_AGRS}|' \
		${WRKSRC}/gui/Makefile
	@${REINPLACE_CMD} -e 's|S_ISBLK|S_ISCHR|' \
		${WRKSRC}/lib/qpxtransport/qpx_mmc.cpp

.include <bsd.port.mk>
