# ex:ts=8
# New ports collection makefile for:   cln
# Date created:                Fab 11, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cln
PORTVERSION=	1.1.6
CATEGORIES=	math devel
MASTER_SITES=	ftp://ftp.ilog.fr/pub/Users/haible/gnu/ \
		ftp://ftp.santafe.edu/pub/gnu/ \
		ftp://ftpthep.physik.uni-mainz.de/pub/gnu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Class Library for Numbers

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--infodir=${PREFIX}/info --mandir=${PREFIX}/man \
		--with-gmp
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

MAN1=		cln-config.1
INFO=		cln

STRIP=		# none

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
BUILD_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
RUN_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
CPPFLAGS+=	-I${LOCALBASE}/include/stlport ${PTHREAD_CFLAGS}
LDFLAGS+=	-lstlport_gcc ${PTHREAD_LIBS}
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/dvi
	${INSTALL_DATA} ${WRKSRC}/doc/*.dvi ${DOCSDIR}/dvi
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}/html
.endif

.include <bsd.port.post.mk>
