# New ports collection makefile for:	silc client
# Date created:				Thu Nov 8 01:50:05 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	silc
PORTVERSION=	1.1
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
MASTER_SITE_SUBDIR=	client/sources
PKGNAMESUFFIX=	-client
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	aquatique-ports@rambler.ru
COMMENT=	Secure Internet Live Conferencing (SILC) network client

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GNOME=	glib12
USE_GMAKE=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--mandir=${MANPREFIX}/man \
		--with-perl=no \
		--without-libtoolfix
MAN1=	silc.1

.ifndef(WITH_PTHREADS)
CONFIGURE_ARGS+=	--without-pthreads
.else
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} ${PTHREAD_LIBS}"
.endif

pre-everything::
.ifndef(WITHOUT_IPV6)
	@${ECHO_MSG} '===> Define WITHOUT_IPV6 to disable IPv6 support'
.endif
.ifndef(WITHOUT_OPTIMIZED_ASM)
	@${ECHO_MSG} '===> Define WITHOUT_OPTIMIZED_ASM to disable assembler optimizations'
.endif
.ifndef(WITH_PTHREADS)
	@${ECHO_MSG} '===> Define WITH_PTHREADS to enable pthreads support'
.endif

post-patch:
# install neither documentation nor silc server, we have ports for those
	@${REINPLACE_CMD} -e 's/-D_THREAD_SAFE//' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's/docdir/DOCDIR/' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's/^install-data-am: install-docDATA$$/install-data-am:/' \
		${WRKSRC}/apps/irssi/docs/Makefile.in
	@${REINPLACE_CMD} -e 's/^install-data-am: install-moduleLTLIBRARIES$$/install-data-am:/' \
		${WRKSRC}/apps/irssi/src/perl/Makefile.in
	@${REINPLACE_CMD} -e 's/--libtool-enable-shared//' \
		${WRKSRC}/lib/silccrypt/Makefile.in
	@${REINPLACE_CMD} -e 's/^MODULESDIR="$$silc_prefix/MODULESDIR="$$silc_prefix\/share\/silc/' ${WRKSRC}/configure

post-install:
	@if [ ! -f ${PREFIX}/etc/silc.conf ]; then \
		${CP} -p ${PREFIX}/etc/silc.conf.sample ${PREFIX}/etc/silc.conf ; \
	fi

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
WITHOUT_OPTIMIZED_ASM=	yes
.endif

.ifndef(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.ifdef(WITHOUT_OPTIMIZED_ASM)
CONFIGURE_ARGS+=	--disable-asm
.endif

.include <bsd.port.post.mk>
