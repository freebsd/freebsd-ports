# New ports collection makefile for:   slrn
# Date created:        28 March 1997
# Whom:                Carey Jones <mcj@acquiesce.org>
#
# $FreeBSD$
#

PORTNAME=	slrn
PORTVERSION=	0.9.7.0
CATEGORIES=	news ipv6
MASTER_SITES=	ftp://slrn.sourceforge.net/pub/slrn/
DISTNAME=	slrn-0.9.7.0a

MAINTAINER=	xaa+ports@timewasters.nl

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all slrnpull
MAN1=		slrn.1

CONFIGURE_ARGS=	--enable-ipv6

.if defined(WITH_SSL)
USE_OPENSSL=	YES
CONFIGURE_ARGS+=	--with-ssl
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${MACHINE_ARCH}objs/slrn ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/${MACHINE_ARCH}objs/slrnpull ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/examples/slrn
	${INSTALL_DATA} ${WRKSRC}/doc/slrn.rc ${PREFIX}/share/examples/slrn
	@${MKDIR} ${PREFIX}/share/examples/slrn/slrnpull
	${INSTALL_DATA} ${WRKSRC}/slrnpull/QUICK_INSTALL ${PREFIX}/share/examples/slrn/slrnpull
	${INSTALL_DATA} ${WRKSRC}/slrnpull/README ${PREFIX}/share/examples/slrn/slrnpull
	${INSTALL_DATA} ${WRKSRC}/slrnpull/score ${PREFIX}/share/examples/slrn/slrnpull
	${INSTALL_DATA} ${WRKSRC}/slrnpull/slrn.rc ${PREFIX}/share/examples/slrn/slrnpull
	${INSTALL_DATA} ${WRKSRC}/slrnpull/slrnpull.conf ${PREFIX}/share/examples/slrn/slrnpull
	${INSTALL_DATA} ${WRKSRC}/slrnpull/slrnpull.sh ${PREFIX}/share/examples/slrn/slrnpull
	${INSTALL_MAN} ${WRKSRC}/doc/slrn.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
