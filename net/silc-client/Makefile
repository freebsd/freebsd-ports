# New ports collection makefile for:	silc client
# Date created:				Thu Nov 8 01:50:05 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	silc
PORTVERSION=	1.1.8
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
PKGNAMESUFFIX=	${IRSSI_PLUGIN}-client
DISTNAME=	${PORTNAME}-client-${PORTVERSION}

MAINTAINER?=	wxs@FreeBSD.org
COMMENT=	Secure Internet Live Conferencing (SILC) network client

CONFLICTS=	silc-toolkit-1.1.* silc-irssi-plugin-1.1.*

MAKE_JOBS_SAFE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib12
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--without-libtoolfix

OPTIONS=	PTHREADS "Enable pthreads support" off \
		IPV6 "Enable IPv6 support" on \
		ICONV "Enable international character support" on \
		PERL "Enable perl support" on \
		OPTIMIZED_ASM "Use assembler optimizations (i386 only)" on

.ifdef(IRSSI_PLUGIN)
CONFIGURE_ARGS+=	--with-silc-plugin=${PREFIX}/lib/irssi \
			--without-silc-includes
CFLAGS+=	-fPIC
RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi
# We don't want to install the man page and configuration file for this case
# Also, the port makes an extra symlink which causes IRSSI to load the plugin
# twice.  This causes weird behavior such as /me output showing up twice.
EXTRA_PATCHES=	${FILESDIR}/extra-patch-apps__irssi__Makefile.in \
		${FILESDIR}/extra-patch-apps__irssi__src__fe-common__Makefile.in
.else
MAN1=		silc.1
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
.ifndef(IRSSI_PLUGIN)
	@if [ ! -f ${PREFIX}/etc/silc.conf ]; then \
		${CP} -p ${PREFIX}/etc/silc.conf.sample ${PREFIX}/etc/silc.conf ; \
	fi
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
WITHOUT_OPTIMIZED_ASM=	yes
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITH_ICONV)
USE_ICONV=		yes
CONFIGURE_ARGS+=	--with-iconv
.else
CONFIGURE_ARGS+=	--without-iconv
.endif

.if defined(WITH_PERL)
USE_PERL5=		yes
PERL_ARCHNAME!=		${PERL} -V:archname 2>/dev/null || true
PLIST_SUB+=		WITH_PERL="" PERL_ARCHNAME=${PERL_ARCHNAME:S/archname='//:S/';//}
CONFIGURE_ARGS+=	--with-perl-lib=${PREFIX}/lib/${PORTNAME}/perl
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=		WITH_PERL="@comment "
.endif

.if defined(WITHOUT_OPTIMIZED_ASM)
CONFIGURE_ARGS+=	--disable-asm
.endif

.if defined(WITH_PTHREADS)
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} ${PTHREAD_LIBS}"
.else
CONFIGURE_ARGS+=	--without-pthreads
.endif

.include <bsd.port.post.mk>
