# ex:ts=8
# New ports collection makefile for:	GiNaC
# Date created:			Mar 7, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GiNaC
PORTVERSION=	1.1.6
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/GiNaC/ \
		http://www.ginac.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ library for symbolic mathematical calculations

LIB_DEPENDS=	cln.3:${PORTSDIR}/math/cln

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		MAKEINFO="makeinfo --no-split"
INSTALLS_SHLIB=	yes

MAN1=	ginac-config.1 ginsh.1 viewgar.1
INFO=	ginac

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
BUILD_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
RUN_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
CPPFLAGS+=	-I${LOCALBASE}/include/stlport ${PTHREAD_CFLAGS}
LDFLAGS+=	-lstlport_gcc ${PTHREAD_LIBS}
CFLAGS+=	-O0
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/tutorial/ginac.info*

.include <bsd.port.post.mk>
