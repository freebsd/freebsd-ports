# New ports collection makefile for:	silc client
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
MASTER_SITE_SUBDIR=	client/sources
PKGNAMESUFFIX=	-client
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

.ifndef(NOPORTDOCS)
RUN_DEPENDS=	${LOCALBASE}/share/doc/silc/CREDITS:${.CURDIR}/../silc-doc
.endif

USE_BZIP2=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GNOMENG=	yes
USE_GNOME=	glib12
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc/${PORTNAME} \
		--with-simdir=${PREFIX}/lib/silcsim/client \
		--with-helpdir=${PREFIX}/share/${PORTNAME}/help
INSTALLS_SHLIB=	yes
PLIST_SUB=	INSTALL_DIR="${INSTALL_DIR}"
PKGDEINSTALL=	${PKGINSTALL}

INSTALL_DIR?=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755

.ifndef(WITH_PTHREADS)
CONFIGURE_ARGS+=	--disable-threads
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
	@${ECHO_MSG}
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} '===> Define WITH_OPTIMIZED_CFLAGS to enable compilation optimizations'
	@${ECHO_MSG} '===> which is known to break some platforms (e.g., alpha)'
.endif

post-patch:
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${PERL} -pi -e 's/-O2//' ${WRKSRC}/${CONFIGURE_SCRIPT}
.endif
# install neither documentation nor silc server, we have ports for those
	@${PERL} -pi -e 's/-D_THREAD_SAFE//; \
		s/^(SILC_DIST_SUBDIRS.+?)doc/\1/' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${PERL} -pi -e 's/example_silcd.conf \\\n//' ${WRKSRC}/doc/Makefile.in
	@${PERL} -pi -e 's/^(install-data-am:) install-docDATA$$/\1/' \
		${WRKSRC}/irssi/docs/Makefile.in
	@${PERL} -pi -e 's/^(install-data-am:) install-moduleLTLIBRARIES$$/\1/' \
		${WRKSRC}/irssi/src/perl/Makefile.in
	@${PERL} -pi -e 's/--libtool-enable-shared//' \
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

.if ${OSVERSION} >= 400014 && !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.ifdef(WITHOUT_OPTIMIZED_ASM)
CONFIGURE_ARGS+=	--disable-asm
.endif

.include <bsd.port.post.mk>
