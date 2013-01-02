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
		http://ftp.sunet.se/pub/network/silc/%SUBDIR%/ \
		ftp://ftp.silcnet.org/silc/%SUBDIR%/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.silcnet.org/silc/%SUBDIR%/ \
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
USE_GNOME=	glib20
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--without-libtoolfix
WANT_PERL=	yes

OPTIONS_DEFINE=	PTHREADS IPV6 ICONV PERL
OPTIONS_DEFINE_i386=	ASM
PTHREADS_DESC=	Enable pthreads support
OPTIONS_DEFAULT=	IPV6 ICONV PERL ASM

.ifdef(IRSSI_PLUGIN)
CONFIGURE_ARGS+=	--with-silc-plugin=${PREFIX}/lib/irssi \
			--without-silc-includes
CFLAGS+=	-fPIC
BUILD_DEPENDS=	irssi:${PORTSDIR}/irc/irssi
# We don't want to install the man page and configuration file for this case
# Also, the port makes an extra symlink which causes IRSSI to load the plugin
# twice.  This causes weird behavior such as /me output showing up twice.
EXTRA_PATCHES=	${FILESDIR}/extra-patch-apps__irssi__Makefile.in \
		${FILESDIR}/extra-patch-apps__irssi__src__fe-common__Makefile.in

# Following is to fix plugin errors. Fixes taken from debian bug report #522080
# and #577501 modified to work with port build process
EXTRA_PATCHES += \
		${FILESDIR}/extra-patch-apps__irssi__src__perl__silc__Makefile.PL.in \
		${FILESDIR}/extra-patch-apps__irssi__src__fe-common__silc__Makefile.in \
		${FILESDIR}/extra-patch-apps__irssi__src__silc__core__Makefile.in \
		${FILESDIR}/extra-patch-apps__irssi__src__silc__core__silc-core.c \
		${FILESDIR}/extra-patch-apps__irssi__src__silc__core__silc-expandos.c \
		${FILESDIR}/extra-patch-apps__irssi__src__silc__core__client_ops.c
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MICONV}
USE_ICONV=		yes
CONFIGURE_ARGS+=	--with-iconv
.else
CONFIGURE_ARGS+=	--without-iconv
.endif

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=		yes
PERL_ARCHNAME!=		perl -V:archname 2>/dev/null || true
PLIST_SUB+=		WITH_PERL="" PERL_ARCHNAME="${PERL_ARCHNAME:S/archname='//:S/';//}"
CONFIGURE_ARGS+=	--with-perl-lib=${PREFIX}/lib/${PORTNAME}/perl
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=		WITH_PERL="@comment "
.endif

.if empty(${PORT_OPTIONS:MASM})
CONFIGURE_ARGS+=	--disable-asm
.endif

.if ${PORT_OPTIONS:MPTHREADS}
CFLAGS+=		${PTHREAD_CFLAGS} ${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=	--without-pthreads
.endif

.include <bsd.port.mk>
