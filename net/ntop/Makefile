# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	ntop
PORTVERSION=	5.0.1
PORTREVISION=	8
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Stable

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network monitoring tool with command line and web interfaces

LICENSE=	GPLv3

LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm \
		libevent.so:${PORTSDIR}/devel/libevent2
BUILD_DEPENDS=	rrdtool>=1.2:${PORTSDIR}/databases/rrdtool \
		dot:${PORTSDIR}/graphics/graphviz \
		geoiplookup:${PORTSDIR}/net/GeoIP
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		urwfonts>0:${PORTSDIR}/x11-fonts/urwfonts

DBDIR?=		/var/db

USES=		gmake libtool python
USE_AUTOTOOLS=	automake autoconf libtoolize
USE_GNOME=	libxml2
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
PLIST_SUB=	DBDIR=${DBDIR} \
		PORTVERSION=${PORTVERSION}
CONFIGURE_ARGS=	--localstatedir=${DBDIR} \
		--with-ossl-root=${OPENSSLBASE} \
		--with-gdbm-root=${LOCALBASE} \
		--with-zlib-root=/usr
INSTALL_TARGET=	install-strip

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
JUMBO_FRAMES_DESC=	Jumbo Frames (experimental)
MAKO_DESC=		Install py-mako for Host Map, Region View

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPCAP_PORT}
LIB_DEPENDS+=		libpcap.so:${PORTSDIR}/net/libpcap
CONFIGURE_ARGS+=	--with-pcap-root=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-pcap-root=/usr
.endif

.if ${PORT_OPTIONS:MXMLDUMP}
LIB_DEPENDS+=		libgdome.so:${PORTSDIR}/textproc/gdome2
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

.include <bsd.port.pre.mk>

# Quick and dirty hackaround - older binutils barf when asked to strip
# an .a file, newer complain about missing sections and succeed.
# The real fix would be for ntop to not try stripping .a files,
# but upstream seems to have gone ahead with ntopng so this may not
# ever be fixed.
.if ${OSVERSION} < 900033
USE_BINUTILS=	yes
CONFIGURE_ARGS+=	STRIP=${LOCALBASE}/bin/strip
.endif

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${SCRIPTS_ENV} ${SH} autogen.sh --noconfig

pre-install:
	@cd ${WRKSRC} && ${MAKE_CMD} dnetter

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ntop/plugins/*.so

.include <bsd.port.post.mk>
