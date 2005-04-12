# ex:ts=8
# New ports collection makefile for:	librsync
# Date created:			Mar 13, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	librsync
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	steve@ion.lu
COMMENT=	Library for delta compression of streams

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-shared --disable-trace
INSTALLS_SHLIB=	yes

MAN3=	librsync.3

post-patch:
	@${REINPLACE_CMD} -e 's|= rdiff.1|=|g' ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
