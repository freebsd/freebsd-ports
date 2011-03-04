# New ports collection makefile for:	cryptlib
# Date created:				17 Jun 2003
# Whom:					Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		cryptlib
PORTVERSION=		3.4.0
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.franken.de/pub/crypt/cryptlib/
DISTNAME=		cl${PORTVERSION:S/.//g}

MAINTAINER=		ale@FreeBSD.org
COMMENT=		A powerful security programming toolkit

ONLY_FOR_ARCHS=		i386 amd64

USE_ZIP=		yes
EXTRACT_BEFORE_ARGS=	-aq
NO_WRKSUBDIR=		yes
USE_GMAKE=		yes
MAKEFILE=		makefile
ALL_TARGET=		default FreeBSD shared
USE_LDCONFIG=		yes

PLIST_FILES=		include/cryptlib.h \
			lib/libcl.a lib/libcl.so \
			lib/libcl.so.3 lib/libcl.so.${PORTVERSION}

PORTDOCS=		README

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/%%CFLAGS%%/${CFLAGS}/' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's/%%PTHREAD_CFLAGS%%/${PTHREAD_CFLAGS}/' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's/%%PTHREAD_LIBS%%/${PTHREAD_LIBS}/' ${WRKSRC}/tools/getlibs.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/libcl.a ${WRKSRC}/libcl.so.${PORTVERSION} \
		${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libcl.so.${PORTVERSION} ${PREFIX}/lib/libcl.so.3
	${LN} -sf ${PREFIX}/lib/libcl.so.3 ${PREFIX}/lib/libcl.so
	${INSTALL_DATA} ${WRKSRC}/cryptlib.h ${PREFIX}/include

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
