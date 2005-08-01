# New ports collection makefile for:   ntop
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	ntop
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pre/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Network monitoring tool with command line and web interfaces

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd \
		gdbm.3:${PORTSDIR}/databases/gdbm \
		png.5:${PORTSDIR}/graphics/png

DBDIR?=		/var/db
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_OPENSSL=	yes
USE_INC_LIBTOOL_VER=13
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
BROKEN=			Does not build with XML dump support
LIB_DEPENDS+=		gdome.8:${PORTSDIR}/textproc/gdome2
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include/libxml2 \
			-I${LOCALBASE}/include/libxml2/libxml \
			-I${LOCALBASE}/include/libgdome \
			-I${LOCALBASE}/include/glib-2.0"
.endif

pre-everything:: show-options

show-options:
	@${SED} -ne 's/^##//p' ${.CURDIR}/Makefile

post-extract:
	@${RM} ${WRKSRC}/configureextra/FREEBSD

post-install:
	@${MKDIR} ${DBDIR}/ntop
	@${CHOWN} -R nobody:nobody ${DBDIR}/ntop
	@${RMDIR} ${PREFIX}/lib/plugins
	@${SED} -e "s#%%PREFIX%%#${PREFIX}#g;s#%%DBDIR%%#${DBDIR}#g" \
		${FILESDIR}/ntop.sh > ${WRKDIR}/ntop.sh
	@${INSTALL_DATA} ${WRKDIR}/ntop.sh ${PREFIX}/etc/rc.d
	@${SED} "s,%%LOCALBASE%%,${LOCALBASE},g" < ${PKGMESSAGE}

.include <bsd.port.post.mk>
