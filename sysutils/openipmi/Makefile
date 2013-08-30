# Created by: Alex Deiter <alex.deiter@gmail.com>
# $FreeBSD$

PORTNAME=	openipmi
PORTVERSION=	2.0.19
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/OpenIPMI%202.0%20Library
DISTNAME=	OpenIPMI-${PORTVERSION}

MAINTAINER=	alex.deiter@gmail.com
COMMENT=	Complex IPMI management software

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf autoheader automake aclocal libtool

AUTOMAKE_ARGS+=	--add-missing --copy --foreign
ACLOCAL_ARGS+=	-I ${LOCALBASE}/share/aclocal
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		ipmi_ui.1 openipmicmd.1 openipmigui.1 \
		openipmish.1 rmcp_ping.1 solterm.1
MAN7=		ipmi_cmdlang.7 openipmi_conparms.7
MAN8=		ipmilan.8

OPTIONS_DEFINE=	SSL SNMP PERL PYTHON TCL TKINTER TRACE GDBM
OPTIONS_RADIO=	GLIB
OPTIONS_RADIO_GLIB=	GLIB12 GLIB20
SSL_DESC=	IPMI 2.0 RMCP+ encryption and authentication
SNMP_DESC=	SNMP trap support for the sample programs
PERL_DESC=	Perl interface for OpenIPMI library
PYTHON_DESC=	Python interface for OpenIPMI library
TCL_DESC=	TCL interface for OpenIPMI library
TKINTER_DESC=	GUI for OpenIPMI, written in Python
TRACE_DESC=	Enable backtrace inspecting
GDBM_DESC=	Local SDR caching on startup
GLIB12_DESC=	Simply OS handler for glib 1.2
GLIB20_DESC=	Simply OS handler for glib 2.0

.include <bsd.port.options.mk>

.if exists(${LOCALBASE}/lib/libgdbm.so.3)
PORT_OPTIONS+=	GDBM
.endif

.if ${PORT_OPTIONS:MSNMP}
PORT_OPTIONS+=		SSL
LIB_DEPENDS+=		netsnmp:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--with-ucdsnmp=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-ucdsnmp=no
.endif

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--with-openssl=no
.endif

.if ${PORT_OPTIONS:MTKINTER}
WITH_TCL=		yes
USE_PYTHON=		yes
WITH_PYTHON=		yes
BUILD_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter \
			${LOCALBASE}/lib/Tix8.4.3/Tix.tcl:${PORTSDIR}/x11-toolkits/tix
CONFIGURE_ARGS+=	--with-tkinter
PLIST_SUB+=		TKINTER=""
.else
CONFIGURE_ARGS+=	--with-tkinter=no
PLIST_SUB+=		TKINTER="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
WITH_SWIG=		yes
USE_PERL5=		yes
CONFIGURE_ARGS+=	--with-perl
PLIST_SUB+=		PERL=""
.else
CONFIGURE_ARGS+=	--with-perl=no
PLIST_SUB+=		PERL="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
WITH_SWIG=		yes
USE_PYTHON=		yes
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=		PYTHON=""
.else
CONFIGURE_ARGS+=	--with-python=no
PLIST_SUB+=		PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MSWIG}
BUILD_DEPENDS+=		swig:${PORTSDIR}/devel/swig13
CONFIGURE_ARGS+=	--with-swig
.else
CONFIGURE_ARGS+=	--with-swig=no
.endif

.if ${PORT_OPTIONS:MTCL}
USE_TCL=		84
CONFIGURE_ARGS+=	--with-tcl \
			--with-tclcflags=-I${TCL_INCLUDEDIR} \
			--with-tcllibs=-ltcl${TCL_VER:S/.//}
PLIST_SUB+=		TCL=""
.else
CONFIGURE_ARGS+=	--with-tcl=no
PLIST_SUB+=		TCL="@comment "
.endif

.if ${PORT_OPTIONS:MTRACE}
LIB_DEPENDS+=		execinfo.1:${PORTSDIR}/devel/libexecinfo
.endif

.if ${PORT_OPTIONS:MGDBM}
LIB_DEPENDS+=		gdbm.4:${PORTSDIR}/databases/gdbm
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

.include <bsd.port.mk>
