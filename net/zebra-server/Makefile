# New ports collection makefile for:	zebra-server
# Date created:				14 Nov 2000
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zebra-server
PORTVERSION=	1.3.0
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/zebra/
DISTNAME=	zebra-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/tclsh8.3:${PORTSDIR}/lang/tcl83
LIB_DEPENDS=	yaz.1:${PORTSDIR}/net/yaz
RUN_DEPENDS=	${LOCALBASE}/bin/tclsh8.3:${PORTSDIR}/lang/tcl83

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-yazconfig=${LOCALBASE}/bin \
		--with-tclconfig=${LOCALBASE}/lib/tcl8.3
CONFIGURE_ENV+=	PTHREAD_LIBS=${PTHREAD_LIBS}

post-install:
.if !defined(NOPORTDOCS)
		@(cd ${WRKSRC}/doc; ${MAKE} install)
.endif

.include <bsd.port.mk>
