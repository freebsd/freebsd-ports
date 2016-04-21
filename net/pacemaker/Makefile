# Created by: dpejesh@yahoo.com
# $FreeBSD$

PORTNAME=	pacemaker
PORTVERSION=	1.1.14
CATEGORIES=	net

MAINTAINER=	dpejesh@yahoo.com
COMMENT=	Scalable High-Availability cluster resource manager

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	bash:shells/bash \
		corosync:net/corosync
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libltdl.so:devel/libltdl \
		libqb.so:devel/libqb \
		libuuid.so:misc/e2fsprogs-libuuid \
		libxml2.so:textproc/libxml2 \
		libxslt.so:textproc/libxslt
RUN_DEPENDS=	bash:shells/bash \
		corosync:net/corosync

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

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_VARS_OFF=		REPLACE_ARGS+="-e 's/HAVE_dbus=1/HAVE_dbus=0/'"

DOCS_BUILD_DEPENDS=	asciidoc:textproc/asciidoc

MANPAGES_BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
			help2man:misc/help2man \
			xsltproc:textproc/libxslt

SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_WITH=	snmp

post-patch:
	@${REINPLACE_CMD} ${REPLACE_ARGS} ${WRKSRC}/configure.ac

post-install:
	${RM} ${STAGEDIR}${PREFIX}/etc/rc.d/pacemaker
	${RM} ${STAGEDIR}${PREFIX}/etc/rc.d/pacemaker_remote

.include <bsd.port.mk>
