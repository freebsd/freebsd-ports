# New ports collection makefile for:   ntop
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	ntop
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pre/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wxs@csh.rit.edu
COMMENT=	Network monitoring tool with command line and web interfaces

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd \
		gdbm.3:${PORTSDIR}/databases/gdbm \
		png.5:${PORTSDIR}/graphics/png

DBDIR?=		/var/db

# Only need to be interactive if it's the first install.
.if !exists(${DBDIR}/ntop/ntop_pw.db)
IS_INTERACTIVE=	yes
.endif

USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB+=	DBDIR=${DBDIR} \
		SHLIB=${PORTVERSION:S/.p/pre/}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--localstatedir=${DBDIR} \
		--with-ossl-root=${OPENSSLBASE} \
		--with-gdbm-root=${LOCALBASE} \
		--with-gd-root=${LOCALBASE} \
		--with-libpng-root=${LOCALBASE} \
		--with-zlib-root=/usr
# we currently disable IPv6
CONFIGURE_ARGS+=--disable-ipv6

MAN8=		ntop.8

USE_RC_SUBR=	ntop.sh

##
## Available knobs:
##    WITH_LOCALE:        Enable locale (i18n) support.
##    WITH_PCAP_PORT:     Use libpcap from ports.
##    WITH_XMLDUMP:       Enable XML Dump support.
##
##    WITHOUT_TCPWRAPPER: Disable TCP wrapper support.
##
OPTIONS=	LOCALE "Enable locale (i18n) support." Off \
		PCAP_PORT "Use libpcap from ports." Off \
		XMLDUMP "Enable XML Dump support." Off \
		TCPWRAPPER "Enable TCP wrapper support" On

.include <bsd.port.pre.mk>

.if defined(WITH_TCPWRAPPER)
CONFIGURE_ARGS+=	--with-tcpwrap
.endif

.if defined(WITH_PCAP_PORT)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
PCAP_ROOT=		${LOCALBASE}
.else
PCAP_ROOT=		/usr
.endif
CONFIGURE_ARGS+=	--with-pcap-root=${PCAP_ROOT}

.if defined(WITH_LOCALE)
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-i18n \
			--with-localedir=${LOCALBASE}/share/locale
.endif

.if defined(WITH_XMLDUMP)
BROKEN=			"Does not build with XML dump support"
LIB_DEPENDS+=		gdome.8:${PORTSDIR}/textproc/gdome2
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include/libxml2 \
			-I${LOCALBASE}/include/libxml2/libxml \
			-I${LOCALBASE}/include/libgdome \
			-I${LOCALBASE}/include/glib-2.0"
.endif

post-extract:
	@${RM} ${WRKSRC}/configureextra/FREEBSD

post-install:
	@${MKDIR} ${DBDIR}/ntop
	@${CHOWN} -R nobody:nobody ${DBDIR}/ntop
	@${RMDIR} ${PREFIX}/lib/plugins
	@if [ ! -f ${DBDIR}/ntop/ntop_pw.db ]; then \
		${PREFIX}/bin/ntop -u nobody -A; \
	fi

.include <bsd.port.post.mk>
