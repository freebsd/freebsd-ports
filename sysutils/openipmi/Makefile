# Created by: Alex Deiter <alex.deiter@gmail.com>
# $FreeBSD$

PORTNAME=	openipmi
PORTVERSION=	2.0.21
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/OpenIPMI%202.0%20Library
DISTNAME=	OpenIPMI-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complex IPMI management software

LICENSE=	GPLv2

LIB_DEPENDS=	libpopt.so:devel/popt

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool ncurses pathfix pkgconfig
USE_LDCONFIG=	yes

CPPFLAGS+=	-I../include -I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	SSL SNMP PERL PYTHON TCL TKINTER GDBM
OPTIONS_RADIO=	GLIB
OPTIONS_RADIO_GLIB=	GLIB12 GLIB20
SSL_DESC=	IPMI 2.0 RMCP+ encryption and authentication
SNMP_DESC=	SNMP trap support for the sample programs
PERL_DESC=	Perl interface for OpenIPMI library
PYTHON_DESC=	Python interface for OpenIPMI library
TCL_DESC=	TCL interface for OpenIPMI library
TKINTER_DESC=	GUI for OpenIPMI, written in Python
GDBM_DESC=	Local SDR caching on startup
GLIB12_DESC=	Simply OS handler for glib 1.2
GLIB20_DESC=	Simply OS handler for glib 2.0

.include <bsd.port.options.mk>

.if exists(${LOCALBASE}/lib/libgdbm.so.3)
PORT_OPTIONS+=	GDBM
.endif

.if ${PORT_OPTIONS:MSNMP}
PORT_OPTIONS+=		SSL
LIB_DEPENDS+=		libnetsnmp.so:net-mgmt/net-snmp
CONFIGURE_ARGS+=	--with-ucdsnmp=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-ucdsnmp=no
.endif

.if ${PORT_OPTIONS:MSSL}
USES+=	ssl
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--with-openssl=no
.endif

.if ${PORT_OPTIONS:MTKINTER}
USES+=			python
WITH_PYTHON=		yes
BUILD_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter \
			${LOCALBASE}/lib/Tix8.4.3/Tix.tcl:x11-toolkits/tix
CONFIGURE_ARGS+=	--with-tkinter
PLIST_SUB+=		TKINTER=""
.else
CONFIGURE_ARGS+=	--with-tkinter=no
PLIST_SUB+=		TKINTER="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
WITH_SWIG=		yes
USES+=			perl5
CONFIGURE_ARGS+=	--with-perl
PLIST_SUB+=		PERL=""
.else
CONFIGURE_ARGS+=	--with-perl=no
PLIST_SUB+=		PERL="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USES+=			python
CONFIGURE_ARGS+=	--with-python --with-swig ac_cv_path_pythonprog=${PYTHON_CMD}
BUILD_DEPENDS+=		swig3.0:devel/swig30
PLIST_SUB+=		PYTHON=""
BINARY_ALIAS=		swig=swig3.0
.else
CONFIGURE_ARGS+=	--with-python=no --with-swig=no
PLIST_SUB+=		PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MTCL}
USES+=			tcl
CONFIGURE_ARGS+=	--with-tcl \
			--with-tclcflags=-I${TCL_INCLUDEDIR} \
			--with-tcllibs=-ltcl${TCL_SHLIB_VER}
PLIST_SUB+=		TCL=""
.else
CONFIGURE_ARGS+=	--with-tcl=no
PLIST_SUB+=		TCL="@comment "
.endif

.if ${PORT_OPTIONS:MGDBM}
LIB_DEPENDS+=		libgdbm.so:databases/gdbm
.endif

.if ${PORT_OPTIONS:MGLIB12}
USE_GNOME+=		glib12
CONFIGURE_ARGS+=	--with-glib12 --with-glibver=1.2
PLIST_SUB+=		GLIB12=""
.else
CONFIGURE_ARGS+=	--with-glib12=no
PLIST_SUB+=		GLIB12="@comment "
.endif

.if ${PORT_OPTIONS:MGLIB20}
USE_GNOME+=		glib20
CONFIGURE_ARGS+=	--with-glib --with-glibver=2.0
PLIST_SUB+=		GLIB20=""
.else
CONFIGURE_ARGS+=	--with-glib=no
PLIST_SUB+=		GLIB20="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} '/libOpenIPMIutils_la_LIBADD =/s/$$/ -lexecinfo/' \
		${WRKSRC}/utils/Makefile.in
	@${REINPLACE_CMD} 's|malloc.h|stdlib.h|' \
		${WRKSRC}/lanserv/sdrcomp/sdrcomp.c \
		${WRKSRC}/lanserv/extcmd.c \
		${WRKSRC}/lanserv/bmc_app.c \
		${WRKSRC}/lanserv/bmc_storage.c \
		${WRKSRC}/lanserv/bmc_picmg.c \
		${WRKSRC}/lanserv/bmc_sensor.c
	@${REINPLACE_CMD} 's|-ldl||' \
		${WRKSRC}/lanserv/Makefile.in

.include <bsd.port.mk>
