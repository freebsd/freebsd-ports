# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	qpxtool
DISTVERSION=	0.7.1_002
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION:C/\.[^.]*$/.x/}/${DISTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A GUI for testing CD/DVD quality and transfer rate

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT4=	qmake_build moc_build rcc_build linguist_build corelib gui network
QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX=${PREFIX}
USE_LDCONFIG=	yes

MAN1=		f1tattoo.1 cdvdcontrol.1 qscan.1 readdvd.1 qpxtool.1 qscand.1
MAN8=		pxfw.8
MANCOMPRESSED=	yes

post-configure:
	@${REINPLACE_CMD} -e 's|$$(QMAKE4)|& ${QMAKEFLAGS}|' \
		${WRKSRC}/gui/Makefile
	@${REINPLACE_CMD} -e 's|S_ISBLK|S_ISCHR|' \
		${WRKSRC}/lib/qpxtransport/qpx_mmc.cpp

.include <bsd.port.mk>
