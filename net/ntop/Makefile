# New ports collection makefile for:   ntop
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	ntop
PORTVERSION=	3.3.9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Network monitoring tool with command line and web interfaces

BUILD_DEPENDS=	rrdtool>=1.2:${PORTSDIR}/databases/rrdtool \
		geoiplookup:${PORTSDIR}/net/GeoIP
LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm
RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz \
		${LOCALBASE}/lib/X11/fonts/URW/a010013l.afm:${PORTSDIR}/x11-fonts/urwfonts

DBDIR?=		/var/db

MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	libtool:15 automake:19 autoconf:262
USE_GNOME=	libxml2
USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
PLIST_SUB=	DBDIR=${DBDIR} \
		PORTVERSION=${PORTVERSION}
CONFIGURE_ARGS=	--localstatedir=${DBDIR} \
		--with-ossl-root=${OPENSSLBASE} \
		--with-gdbm-root=${LOCALBASE} \
		--with-zlib-root=/usr \
		--disable-snmp
# we currently disable IPv6
CONFIGURE_ARGS+=--disable-ipv6

MAN8=		ntop.8

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-deinstall
SUB_LIST=	DBDIR=${DBDIR}
USE_RC_SUBR=	ntop.sh

##
## Available knobs:
##    WITH_LOCALE:        Enable locale (i18n) support.
##    WITH_PCAP_PORT:     Use libpcap from ports.
##    WITH_XMLDUMP:       Enable XML Dump support.
##    WITH_ASDATA:        Install AS data.
##    WITHOUT_TCPWRAPPER: Disable TCP wrapper support.
##
OPTIONS=	LOCALE "Enable locale (i18n) support." Off \
		PCAP_PORT "Use libpcap from ports." Off \
		XMLDUMP "Enable XML Dump support." Off \
		ASDATA "Install AS data." Off \
		TCPWRAPPER "Enable TCP wrapper support" On

.include <bsd.port.pre.mk>

.if defined(WITH_TCPWRAPPER)
CONFIGURE_ARGS+=	--with-tcpwrap
.endif

.if defined(WITH_PCAP_PORT)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
CONFIGURE_ARGS+=	--with-pcap-root=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-pcap-root=/usr
.endif

.if defined(WITH_LOCALE) && !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-i18n \
			--with-localedir=${LOCALBASE}/share/locale
.endif

.if defined(WITH_XMLDUMP)
LIB_DEPENDS+=		gdome.8:${PORTSDIR}/textproc/gdome2
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include/libxml2 \
			-I${LOCALBASE}/include/libxml2/libxml \
			-I${LOCALBASE}/include/libgdome \
			-I${LOCALBASE}/include/glib-2.0"
.endif

.if defined(WITH_ASDATA)
INSTALL_TARGET+=	install install-data-as
PLIST_SUB+=		ASDATA=""
.else
PLIST_SUB+=		ASDATA="@comment "
.endif

post-extract:
	@${RM} ${WRKSRC}/configureextra/FREEBSD

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${SCRIPTS_ENV} ${SH} autogen.sh --noconfig

post-install:
	@${MKDIR} ${DBDIR}/ntop
	@${CHOWN} -R nobody:nobody ${DBDIR}/ntop

.include <bsd.port.post.mk>
