# New ports collection makefile for:	silc client
# Date created:				Thu Nov 8 01:50:05 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	silc
PORTVERSION=	0.7.2
CATEGORIES=	net security
MASTER_SITES=	http://www.silcnet.org/download/client/sources/ \
		ftp://ftp.silcnet.org/silc/client/sources/ \
		http://www.planetmirror.com/pub/silcnet/client/sources/ \
		ftp://ftp.au.silcnet.org/pub/silcnet/client/sources/ \
		http://the.wiretapped.net/security/network-security/silc/client/sources/ \
		ftp://ftp.wiretapped.net/pub/security/network-security/silc/client/sources/ \
		http://munitions.vipul.net/software/mirrors/silc/ \
		ftp://ftp.no.silcnet.org/pub/silc/client/sources/
PKGNAMESUFFIX=	-client
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

.ifndef(NOPORTDOCS)
RUN_DEPENDS=	${LOCALBASE}/share/doc/silc/CREDITS:${.CURDIR}/../silc-doc
.endif

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GLIB=	yes
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc/${PORTNAME} \
		--with-helpdir=${PREFIX}/share/${PORTNAME}/help
PLIST_SUB=	INSTALL_DIR="${INSTALL_DIR}"
PKGDEINSTALL=	${PKGINSTALL}

INSTALL_DIR?=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755

.ifndef(WITH_PTHREADS)
CONFIGURE_ARGS+=	--disable-threads
.else
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} ${PTHREAD_LIBS}"
.endif

pre-everything::
.ifndef(WITHOUT_OPTIMIZED_ASM)
	@${ECHO_MSG} '===> Define WITHOUT_OPTIMIZED_ASM to disable assembler optimizations'
.endif
.ifndef(WITH_PTHREADS)
	@${ECHO_MSG} '===> Define WITH_PTHREADS to enable pthreads support'
.endif
	@${ECHO_MSG}
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} '===> Define WITH_OPTIMIZED_CFLAGS to enable compilation optimizations'
	@${ECHO_MSG} '===> which is known to break some platforms (e.g., alpha)'
.endif

post-patch:
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${PERL} -pi -e 's/-O2//' ${WRKSRC}/${CONFIGURE_SCRIPT}
.endif

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
WITHOUT_OPTIMIZED_ASM=	yes
.endif

.ifdef(WITHOUT_OPTIMIZED_ASM)
CONFIGURE_ARGS+=	--disable-asm
.endif

.include <bsd.port.post.mk>
