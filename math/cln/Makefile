# ex:ts=8
# New ports collection makefile for:   cln
# Date created:                Fab 11, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cln
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	ftp://ftp.ilog.fr/pub/Users/haible/gnu/ \
		ftp://ftp.santafe.edu/pub/gnu/ \
		ftp://ftpthep.physik.uni-mainz.de/pub/gnu/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gmp.5:${PORTSDIR}/math/libgmp4

USE_LIBTOOL=	yes
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/cln --infodir=${PREFIX}/info \
		--mandir=${PREFIX}/man --with-gmp

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=		cln-config.1

pre-build:
	@(cd ${WRKSRC} ; ${LN} -sf ${LOCALBASE}/bin/libtool .)

.include <bsd.port.mk>
