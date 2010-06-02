# New ports collection makefile for:	sysutils/openipmi
# Date created:				28/Mar/2010
# Whom:					Alex Deiter <alex.deiter@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	openipmi
PORTVERSION=	2.0.18
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/OpenIPMI%202.0%20Library/${PORTVERSION}
DISTNAME=	OpenIPMI-${PORTVERSION}

MAINTAINER=	alex.deiter@gmail.com
COMMENT=	Complex IPMI management software

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	autoconf:262 autoheader:262 automake:110 aclocal:110 libtool:22

AUTOMAKE_ARGS+=	--add-missing --copy --foreign
ACLOCAL_ARGS+=	-I ${LOCALBASE}/share/aclocal
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		ipmi_ui.1 openipmicmd.1 openipmigui.1 \
		openipmish.1 rmcp_ping.1 solterm.1
MAN7=		ipmi_cmdlang.7 openipmi_conparms.7
MAN8=		ipmilan.8

OPTIONS=	SSL	"IPMI 2.0 RMCP+ encryption and authentication"	On  \
		SNMP	"SNMP trap support for the sample programs"	Off \
		PERL	"Perl interface for OpenIPMI library"		Off \
		PYTHON	"Python interface for OpenIPMI library"		Off \
		TCL	"TCL interface for OpenIPMI library"		Off \
		TKINTER	"GUI for OpenIPMI, written in Python"		Off \
		GDBM	"Local SDR caching on startup"			Off \
		GLIB12	"Simply OS handler for glib 1.2"		Off \
		GLIB20	"Simply OS handler for glib 2.0"		Off

.include <bsd.port.options.mk>

.if exists(${LOCALBASE}/lib/libgdbm.so.3)
WITH_GDBM=		yes
.endif

.if defined(WITH_SNMP)
WITH_SSL=		yes
LIB_DEPENDS+=		netsnmp:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--with-ucdsnmp=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-ucdsnmp=no
.endif

.if defined(WITH_SSL)
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--with-openssl=no
.endif

.if defined(WITH_TKINTER)
WITH_TCL=		yes
USE_PYTHON=		yes
WITH_PYTHON=		yes
BUILD_DEPENDS+=		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
			${LOCALBASE}/lib/tix8.1/Tix.tcl:${PORTSDIR}/x11-toolkits/tix
CONFIGURE_ARGS+=	--with-tkinter
PLIST_SUB+=		TKINTER=""
.else
CONFIGURE_ARGS+=	--with-tkinter=no
PLIST_SUB+=		TKINTER="@comment "
.endif

.if defined(WITH_PERL)
WITH_SWIG=		yes
USE_PERL5=		yes
CONFIGURE_ARGS+=	--with-perl
PLIST_SUB+=		PERL=""
.else
CONFIGURE_ARGS+=	--with-perl=no
PLIST_SUB+=		PERL="@comment "
.endif

.if defined(WITH_PYTHON)
WITH_SWIG=		yes
USE_PYTHON=		yes
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=		PYTHON=""
.else
CONFIGURE_ARGS+=	--with-python=no
PLIST_SUB+=		PYTHON="@comment "
.endif

.if defined(WITH_SWIG)
BUILD_DEPENDS+=		swig:${PORTSDIR}/devel/swig13
CONFIGURE_ARGS+=	--with-swig
.else
CONFIGURE_ARGS+=	--with-swig=no
.endif

.if defined(WITH_TCL)
USE_TCL=		84
USE_TCL_THREADS=	yes
CONFIGURE_ARGS+=	--with-tcl \
			--with-tclcflags=-I${TCL_INCLUDEDIR} \
			--with-tcllibs=-ltcl${TCL_VER:S/.//}
PLIST_SUB+=		TCL=""
.else
CONFIGURE_ARGS+=	--with-tcl=no
PLIST_SUB+=		TCL="@comment "
.endif

.if defined(WITH_GDBM)
LIB_DEPENDS+=		gdbm.3:${PORTSDIR}/databases/gdbm
.endif

.if defined(WITH_GLIB12)
USE_GNOME+=		glib12
CONFIGURE_ARGS+=	--with-glib12 --with-glibver=1.2
PLIST_SUB+=		GLIB12=""
.else
CONFIGURE_ARGS+=	--with-glib12=no
PLIST_SUB+=		GLIB12="@comment "
.endif

.if defined(WITH_GLIB20)
USE_GNOME+=		glib20
CONFIGURE_ARGS+=	--with-glib --with-glibver=2.0
PLIST_SUB+=		GLIB20=""
.else
CONFIGURE_ARGS+=	--with-glib=no
PLIST_SUB+=		GLIB20="@comment "
.endif

.if defined(WITH_GLIB12) && defined(WITH_GLIB20)
IGNORE=selected mutually exclusive options: WITH_GLIB12 and WITH_GLIB20
.endif

.include <bsd.port.mk>
