# New ports collection makefile for:	mfm
# Date created:				12 Jan 2000
# Whom:					Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	mfm
PORTVERSION= 	1.5
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.core-coutainville.org/mfm/archive/SOURCES/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	mtools:${PORTSDIR}/emulators/mtools

USE_X_PREFIX=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-conffile="${PREFIX}/etc/mfm.conf" \
		--with-mtoolsdir="${LOCALBASE}/bin" \
		--disable-gtktest

MAN1=		mfm.1

.include <bsd.port.mk>
