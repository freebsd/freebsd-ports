# New ports collection makefile for:	cryptlib
# Date created:				17 Jun 2003
# Whom:					Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		cryptlib
PORTVERSION=		3.3.1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.franken.de/pub/crypt/cryptlib/
DISTNAME=		cl${PORTVERSION:S/.//g}
EXTRACT_SUFX=		.zip

MAINTAINER=		ale@FreeBSD.org
COMMENT=		A powerful security programming toolkit

OPTIONS=		OPTIMIZED_CFLAGS	"Build with optimized CFLAGS" off

ONLY_FOR_ARCHS=		i386

USE_ZIP=		yes
EXTRACT_BEFORE_ARGS=	-aq
NO_WRKSUBDIR=		yes
USE_GMAKE=		yes
MAKEFILE=		makefile
ALL_TARGET=		default FreeBSD shared
USE_LDCONFIG=		yes

PORTDOCS=		README

.include <bsd.port.pre.mk>

post-patch:
.if defined(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's/%%CFLAGS%%/${CFLAGS:N-O*:N-f*} -fomit-frame-pointer -O3/' ${WRKSRC}/makefile
.else
	@${REINPLACE_CMD} -e 's/%%CFLAGS%%/${CFLAGS}/' ${WRKSRC}/makefile
.endif
	@${REINPLACE_CMD} -e 's/%%PTHREAD_CFLAGS%%/${PTHREAD_CFLAGS}/' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's/%%PTHREAD_LIBS%%/${PTHREAD_LIBS}/' ${WRKSRC}/tools/getlibs.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/libcl.a ${WRKSRC}/libcl.so.3.3.0 \
		${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libcl.so.3.3.0 ${PREFIX}/lib/libcl.so.3
	${LN} -sf ${PREFIX}/lib/libcl.so.3 ${PREFIX}/lib/libcl.so
	${INSTALL_DATA} ${WRKSRC}/cryptlib.h ${PREFIX}/include

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
