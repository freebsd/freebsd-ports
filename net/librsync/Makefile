# ex:ts=8
# New ports collection makefile for:	librsync
# Date created:			Mar 13, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	librsync
PORTVERSION=	0.9.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rproxy

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_LIBTOOL=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include"
CONFIGURE_ARGS=	--enable-shared --disable-trace

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=	rdiff.1
MAN3=	librsync.3

pre-build:
	@${LN} -sf ${LOCALBASE}/bin/libtool ${WRKSRC}

.include <bsd.port.mk>
