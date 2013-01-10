# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	ntop
PORTVERSION=	5.0.1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Stable

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Network monitoring tool with command line and web interfaces

LIB_DEPENDS=	gdbm.4:${PORTSDIR}/databases/gdbm \
		event-1.4:${PORTSDIR}/devel/libevent
BUILD_DEPENDS=	rrdtool>=1.2:${PORTSDIR}/databases/rrdtool \
		subversion>=1.7.0:${PORTSDIR}/devel/subversion \
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
		--with-zlib-root=/usr

MAN8=		ntop.8

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CPPFLAGS+=	-I${LOCALBASE}/include
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-deinstall
SUB_LIST=	DBDIR=${DBDIR}
USE_RC_SUBR=	ntop

OPTIONS_DEFINE=	PCAP_PORT XMLDUMP JUMBO_FRAMES MAKO

PCAP_PORT_DESC=		Use libpcap from ports
XMLDUMP_DESC=		Enable XML Dump support
JUMBO_FRAMES_DESC=	Jumbo Frames. Experimental.
MAKO_DESC=		Install py-mako for Host Map, Region View

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPCAP_PORT}
LIB_DEPENDS+=		pcap.1:${PORTSDIR}/net/libpcap
CONFIGURE_ARGS+=	--with-pcap-root=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-pcap-root=/usr
.endif

.if ${PORT_OPTIONS:MXMLDUMP}
LIB_DEPENDS+=		gdome.8:${PORTSDIR}/textproc/gdome2
CPPFLAGS+=		-I${LOCALBASE}/include/libxml2 \
			-I${LOCALBASE}/include/libxml2/libxml \
			-I${LOCALBASE}/include/libgdome \
			-I${LOCALBASE}/include/glib-2.0
.endif

.if ${PORT_OPTIONS:MJUMBO_FRAMES}
CONFIGURE_ARGS+=	--enable-jumbo-frames
# should set your mtu to 9000
# see http://www.cyberciti.biz/faq/freebsd-jumbo-frames-networking-configration/
.endif

.if ${PORT_OPTIONS:MMAKO}
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
