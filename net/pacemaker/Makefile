# Created by: dpejesh@yahoo.com
# $FreeBSD$

PORTNAME=	pacemaker
PORTVERSION=	1.1.16
DISTVERSIONPREFIX=	Pacemaker-
CATEGORIES=	net

MAINTAINER=	dpejesh@yahoo.com
COMMENT=	Scalable High-Availability cluster resource manager

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash \
		corosync:net/corosync \
		getopt>=0:misc/getopt
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libltdl.so:devel/libltdl \
		libqb.so:devel/libqb \
		libuuid.so:misc/e2fsprogs-libuuid \
		libxml2.so:textproc/libxml2 \
		libxslt.so:textproc/libxslt
RUN_DEPENDS=	bash:shells/bash \
		corosync:net/corosync \
		getopt>=0:misc/getopt \
		ocf-tester:net-mgmt/resource-agents

BROKEN_armv6=		fails to install: help2man: can't get '--help' info from pacemakerd
BROKEN_powerpc64=	fails to build

CONFLICTS=	heartbeat-[0-9]*

USERS=		hacluster
GROUPS=		haclient

USE_GITHUB=	yes
GH_ACCOUNT=	ClusterLabs

USES=		autoreconf gmake libtool pathfix pkgconfig python shebangfix
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_PYTHON=	py3kplist
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-fatal-warnings \
		--disable-hardening \
		--with-corosync \
		--without-heartbeat
INSTALL_TARGET=	install-strip

PATHFIX_MAKEFILEIN=	Makefile.am

SHEBANG_LANG=	sh
sh_OLD_CMD=	${SH}
sh_CMD=		${LOCALBASE}/bin/bash
SHEBANG_FILES=	BasicSanity.sh \
		coverage.sh.in \
		cts/CTSlab.py \
		cts/cts \
		cts/lxc_autogen.sh.in \
		extra/resources/* \
		fencing/* \
		lrmd/* \
		mcp/* \
		pengine/regression.sh \
		tools/* \
		xml/*

REPLACE_ARGS_OCF=	-e 's,/usr/lib/ocf,${PREFIX}/lib/ocf,'
REPLACE_ARGS_GETOPT=	-e 's,getopt,${LOCALBASE}/bin/getopt,'

OPTIONS_DEFINE=	DBUS DOCS MANPAGES SNMP
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_VARS_OFF=		REPLACE_ARGS+="-e 's/HAVE_dbus=1/HAVE_dbus=0/'"

DOCS_BUILD_DEPENDS=	asciidoc:textproc/asciidoc

MANPAGES_BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
			help2man:misc/help2man \
			xsltproc:textproc/libxslt

SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_WITH=	snmp

post-patch:
	@${REINPLACE_CMD} ${REPLACE_ARGS_OCF} ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} ${REPLACE_ARGS_GETOPT} ${WRKSRC}/tools/crm_failcount
	@${REINPLACE_CMD} ${REPLACE_ARGS_GETOPT} ${WRKSRC}/tools/crm_master
	@${REINPLACE_CMD} ${REPLACE_ARGS_GETOPT} ${WRKSRC}/tools/crm_report.in
	@${REINPLACE_CMD} ${REPLACE_ARGS_GETOPT} ${WRKSRC}/tools/crm_standby

.include <bsd.port.mk>
