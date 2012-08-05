# New ports collection makefile for:   ntop
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	ntop
PORTVERSION=	4.1.0
PORTREVISION=	5
CATEGORIES=	net
#MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Stable
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Network monitoring tool with command line and web interfaces

LIB_DEPENDS=	gdbm.4:${PORTSDIR}/databases/gdbm \
		event-1.4:${PORTSDIR}/devel/libevent
BUILD_DEPENDS=	rrdtool>=1.2:${PORTSDIR}/databases/rrdtool \
		dot:${PORTSDIR}/graphics/graphviz \
		geoiplookup:${PORTSDIR}/net/GeoIP
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		 ${LOCALBASE}/lib/X11/fonts/URW/a010013l.afm:${PORTSDIR}/x11-fonts/urwfonts

DBDIR?=		/var/db

MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	libtool automake autoconf
USE_GNOME=	libxml2
USE_PYTHON=	2.6+
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

MAN8=		ntop.8

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-deinstall
SUB_LIST=	DBDIR=${DBDIR}
USE_RC_SUBR=	ntop

##
## Available knobs:
##    WITH_PCAP_PORT:     Use libpcap from ports.
##    WITH_XMLDUMP:       Enable XML Dump support.
##    WITH_MAKO:	 Enable Host Map, Region View (installs py-mako)
##
OPTIONS=	PCAP_PORT "Use libpcap from ports." Off \
		XMLDUMP "Enable XML Dump support." Off \
		JUMBO_FRAMES "Jumbo Frames. Experimental." Off \
		MAKO "Install py-mako for Host Map, Region View " Off

.include <bsd.port.pre.mk>

.if defined(WITH_PCAP_PORT)
LIB_DEPENDS+=		pcap.1:${PORTSDIR}/net/libpcap
CONFIGURE_ARGS+=	--with-pcap-root=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-pcap-root=/usr
.endif

.if defined(WITH_XMLDUMP)
LIB_DEPENDS+=		gdome.8:${PORTSDIR}/textproc/gdome2
CPPFLAGS+=		-I${LOCALBASE}/include/libxml2 \
			-I${LOCALBASE}/include/libxml2/libxml \
			-I${LOCALBASE}/include/libgdome \
			-I${LOCALBASE}/include/glib-2.0
.endif

.if defined(WITH_JUMBO_FRAMES)
CONFIGURE_ARGS+=	--enable-jumbo-frames
# should set your mtu to 9000
# see http://www.cyberciti.biz/faq/freebsd-jumbo-frames-networking-configration/
.endif

.if defined(WITH_MAKO)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mako>0:${PORTSDIR}/textproc/py-mako
.endif

.if ${OSVERSION} < 700000
BROKEN=		does not configure on 6.X
.endif

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${SCRIPTS_ENV} ${SH} autogen.sh --noconfig

pre-install:
	@cd ${WRKSRC} && ${GMAKE} dnetter

post-install:
	@${MKDIR} ${DBDIR}/ntop
	@${CHOWN} -R nobody:nobody ${DBDIR}/ntop

.include <bsd.port.post.mk>
