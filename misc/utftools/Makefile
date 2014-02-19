# Created by: Serge Gagnon <gagnon__s@videotron.ca>
# $FreeBSD$

PORTNAME=	utftools
PORTVERSION=	1.6
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cs.yorku.ca/pub/wily/misc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UTF-aware wc, fmt, expand, and unexpand

BUILD_DEPENDS=	${LOCALBASE}/lib/libutf.a:${PORTSDIR}/misc/libutf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${LOCALBASE}/lib --includedir=${LOCALBASE}/include

.include <bsd.port.mk>
