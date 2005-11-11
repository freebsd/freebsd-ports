# New ports collection makefile for:	hyperestraier
# Date created:		2005-09-11
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hyperestraier
PORTVERSION=	1.0.5
PORTREVISION=	0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	A full-text search system

BUILD_DEPENDS=	qdbm>=1.8.33:${PORTSDIR}/databases/qdbm
LIB_DEPENDS=	qdbm.11:${PORTSDIR}/databases/qdbm

USE_ICONV=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=	estcall.1 estcmd.1 estconfig.1 estmaster.1
MAN3=	estnode.3 estraier.3

post-patch:
	@${REINPLACE_CMD} -e 's|@libdir@/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
