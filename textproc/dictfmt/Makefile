# New ports collection makefile for:   dictfmt
# Date created:                19 July 2002
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	dictfmt
PORTVERSION=	1.6.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.dict.org/pub/dict/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	fuyuki@hadaly.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

NO_WRKSUBDIR=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
USE_GMAKE=	yes

MAN1=		dictfmt.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dictfmt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dictfmt.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
