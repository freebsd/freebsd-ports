# New ports collection makefile for:	silc server
# Date created:				Thu Nov 8 01:50:05 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	silc
PORTVERSION=	0.9.18
CATEGORIES=	net ipv6 security
MASTER_SITES=	http://www.silcnet.org/download/%SUBDIR%/ \
		http://ftp.silcnet.org/%SUBDIR%/ \
		http://www.nic.funet.fi/pub/mirrors/ftp.silcnet.org/silc/%SUBDIR%/ \
		http://www.fi.silcnet.org/download/%SUBDIR%/ \
		http://munitions.vipul.net/software/mirrors/silc/%SUBDIR%/ \
		http://www.pl.silcnet.org/download/%SUBDIR%/ \
		http://ftp.sunet.se/pub/network/silc/%SUBDIR%/ \
		ftp://ftp.silcnet.org/silc/%SUBDIR%/ \
		ftp://ftp.au.silcnet.org/pub/silcnet/%SUBDIR%/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.silcnet.org/silc/%SUBDIR%/ \
		ftp://ftp.pl.silcnet.org/pub/silc/%SUBDIR%/ \
		ftp://ftp.sunet.se/pub/network/silc/%SUBDIR%/
MASTER_SITE_SUBDIR=	server/sources
PKGNAMESUFFIX=	-server
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	aquatique-ports@rambler.ru
COMMENT=	Secure Internet Live Conferencing (SILC) network server

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-silcd-config-file=${PREFIX}/etc/${PORTNAME}/silcd.conf \
		--with-etcdir=${PREFIX}/etc/${PORTNAME} \
		--with-helpdir=share/${PORTNAME}/help \
		--with-logsdir=/var/log/${PORTNAME} \
		--with-silcd-pid-file=/var/run/silcd.pid

PLIST_SUB=	INSTALL_DIR="${INSTALL_DIR}"
PKGDEINSTALL=	${PKGINSTALL}

INSTALL_DIR?=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755

MAN5=	silcd.conf.5
MAN8=	silcd.8

.ifndef(WITH_PTHREADS)
CONFIGURE_ARGS+=	--without-pthreads
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

post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/silcd.sh \
	    > ${WRKSRC}/silcd.sh

post-patch:
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e \
		's/(install-data-hook:.*)example-install/\1/' \
		${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's/--libtool-enable-shared//' \
		${WRKSRC}/lib/silccrypt/Makefile.in

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL
	${INSTALL_DATA} ${WRKSRC}/silcd.sh ${PREFIX}/etc/rc.d/silcd.sh-dist
	@if [ ! -f ${PREFIX}/etc/rc.d/silcd.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/silcd.sh startup file."; \
		${INSTALL_SCRIPT} ${WRKSRC}/silcd.sh ${PREFIX}/etc/rc.d/silcd.sh; \
	fi

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
