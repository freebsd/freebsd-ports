# Created by: dpejesh@yahoo.com
# $FreeBSD$

PORTNAME=	pacemaker
PORTVERSION=	1.1.14
CATEGORIES=	net

MAINTAINER=	dpejesh@yahoo.com
COMMENT=	Scalable High-Availability cluster resource manager

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		corosync:${PORTSDIR}/net/corosync
LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libltdl.so:${PORTSDIR}/devel/libltdl \
		libqb.so:${PORTSDIR}/devel/libqb \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libxslt.so:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		corosync:${PORTSDIR}/net/corosync

CONFLICTS=	heartbeat-[0-9]*

USERS=		hacluster
GROUPS=		haclient

USE_GITHUB=	yes
GH_ACCOUNT=	ClusterLabs
GH_PROJECT=	pacemaker
GH_TAGNAME=	Pacemaker-1.1.14

USES=		autoreconf gmake libtool pathfix pkgconfig python shebangfix
USE_GCC=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-fatal-warnings \
		--with-corosync \
		--without-heartbeat
INSTALL_TARGET=	install-strip

PATHFIX_MAKEFILEIN=	Makefile.am

SHEBANG_LANG=	sh
sh_OLD_CMD=	${SH}
sh_CMD=		${LOCALBASE}/bin/bash
SHEBANG_FILES=	extra/resources/* \
		fencing/* \
		lrmd/* \
		mcp/* \
		tools/* \
		xml/*

REPLACE_ARGS=	-e 's,/usr/lib/ocf,${PREFIX}/etc/ocf,'

OPTIONS_DEFINE=	DBUS DOCS MANPAGES SNMP
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

DBUS_LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus
DBUS_VARS_OFF=		REPLACE_ARGS+="-e 's/HAVE_dbus=1/HAVE_dbus=0/'"

DOCS_BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc

MANPAGES_BUILD_DEPENDS=	docbook-xsl>0:${PORTSDIR}/textproc/docbook-xsl \
			help2man:${PORTSDIR}/misc/help2man \
			xsltproc:${PORTSDIR}/textproc/libxslt

SNMP_LIB_DEPENDS=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp
SNMP_CONFIGURE_WITH=	snmp

post-patch:
	@${REINPLACE_CMD} ${REPLACE_ARGS} ${WRKSRC}/configure.ac

post-install:
	${RM} ${STAGEDIR}${PREFIX}/etc/rc.d/pacemaker
	${RM} ${STAGEDIR}${PREFIX}/etc/rc.d/pacemaker_remote

.include <bsd.port.mk>
