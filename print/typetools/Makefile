# Created by: ijliao
# $FreeBSD$

PORTNAME=	typetools
PORTVERSION=	2.98
CATEGORIES=	print
MASTER_SITES=	http://www.lcdf.org/type/
DISTNAME=	lcdf-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for manipulating fonts

LICENSE=	GPLv2

USE_TEX=	base
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_kpathsea_kpathsea_h=yes
CONFIGURE_ARGS=	--with-kpathsea=${LOCALBASE}

MAN1=		cfftot1.1 mmafm.1 mmpfb.1 otfinfo.1 otftotfm.1 t1dotlessj.1 \
		t1lint.1 t1rawafm.1 t1reencode.1 t1testpage.1 ttftotype42.1

DATADIR=	${PREFIX}/share/lcdf-${PORTNAME}

.include <bsd.port.mk>
