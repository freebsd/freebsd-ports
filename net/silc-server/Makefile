# New ports collection makefile for:	silc server
# Date created:				Thu Nov 8 01:50:05 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	silc
PORTVERSION=	0.9.10.1
CATEGORIES=	net ipv6 security
MASTER_SITES=	http://www.silcnet.org/download/%SUBDIR%/ \
		http://ftp.silcnet.org/%SUBDIR%/ \
		http://www.planetmirror.com/pub/silcnet/%SUBDIR%/ \
		http://www.nic.funet.fi/pub/mirrors/ftp.silcnet.org/silc/%SUBDIR%/ \
		http://www.fi.silcnet.org/download/%SUBDIR%/ \
		http://munitions.vipul.net/software/mirrors/silc/%SUBDIR%/ \
		http://www.pl.silcnet.org/download/%SUBDIR%/ \
		http://ftp.sunet.se/pub/network/silc/%SUBDIR%/ \
		ftp://ftp.silcnet.org/silc/%SUBDIR%/ \
		ftp://ftp.au.silcnet.org/pub/silcnet/%SUBDIR%/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.silcnet.org/silc/%SUBDIR%/ \
		ftp://ftp.pl.silcnet.org/pub/silc/%SUBDIR%/ \
		ftp://ftp.sunet.se/pub/network/silc/%SUBDIR%/ \
		ftp://ftp.uk.silcnet.org/pub/silc/%SUBDIR%/
MASTER_SITE_SUBDIR=	server/sources
PKGNAMESUFFIX=	-server
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

.ifndef(NOPORTDOCS)
RUN_DEPENDS=	${LOCALBASE}/share/doc/silc/CREDITS:${.CURDIR}/../silc-doc
.endif

USE_BZIP2=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-silcd-config-file=${PREFIX}/etc/${PORTNAME}/silcd.conf \
		--with-etcdir=${PREFIX}/etc/${PORTNAME} \
		--with-helpdir=share/${PORTNAME}/help \
		--with-logsdir=${PORTNAME}/logs \
		--with-simdir=${PREFIX}/lib/silcsim/server \
		--with-silcd-pid-file=/var/run/silcd.pid
INSTALLS_SHLIB=	yes
PLIST_SUB=	INSTALL_DIR="${INSTALL_DIR}"
PKGDEINSTALL=	${PKGINSTALL}

INSTALL_DIR?=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755

MAN5=	silcd.conf.5
MAN8=	silcd.8

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
	@${REINPLACE_CMD} -e 's/-O2//' ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e \
		's/(install-data-hook:.*)example-install/\1/' \
		${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's/--libtool-enable-shared//' \
		${WRKSRC}/lib/silccrypt/Makefile.in

post-configure:
	@${CP} ${LOCALBASE}/bin/libtool ${WRKSRC}

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
WITHOUT_OPTIMIZED_ASM=	yes
.endif

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.ifdef(WITHOUT_OPTIMIZED_ASM)
CONFIGURE_ARGS+=	--disable-asm
.endif

.include <bsd.port.post.mk>
