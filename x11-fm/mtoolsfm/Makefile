# New ports collection makefile for:	MToolsFM
# Date created:				12 Jan 2000
# Whom:					Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	mtoolsfm
PORTVERSION= 	1.6
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.core-coutainville.org/MToolsFM/archive/SOURCES/
DISTNAME=	MToolsFM-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	mtools:${PORTSDIR}/emulators/mtools

USE_X_PREFIX=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-conffile="${PREFIX}/etc/mfm.conf" \
		--with-mtoolsdir="${LOCALBASE}/bin" \
		--disable-gtktest

MAN1=		mtoolsfm.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/MToolsFM ${PREFIX}/bin/mtoolsfm
	${INSTALL_MAN} ${WRKSRC}/MToolsFM.1 ${MANPREFIX}/man/man1/mtoolsfm.1

.include <bsd.port.mk>
