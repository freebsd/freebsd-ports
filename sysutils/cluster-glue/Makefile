# $FreeBSD$

PORTNAME=	cluster-glue
PORTVERSION=	1.0.12
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://hg.linux-ha.org/glue/archive/
DISTNAME=	0a7add1d9996
DIST_SUBDIR=	linux-ha

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High availability cluster libraries and utilities

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libuuid.so:misc/e2fsprogs-libuuid \
		libnet.so:net/libnet

USES=		autoreconf gettext gmake gnome libtool localbase perl5 pkgconfig python shebangfix \
		tar:bz2 ssl
SHEBANG_FILES=	lib/plugins/stonith/external/ibmrsa-telnet \
		lib/plugins/stonith/external/vmware \
		lib/plugins/stonith/external/xen0-ha.in \
		lib/plugins/stonith/external/xen0-ha-dom0-stonith-helper \
		lib/plugins/stonith/external/riloe \
		lib/plugins/stonith/external/dracmc-telnet
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes
USE_RC_SUBR=	ha_logd
WRKSRC=		${WRKDIR}/Reusable-Cluster-Components-glue--${DISTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-fatal-warnings \
		--with-initdir=${PREFIX}/etc/rc.d \
		--with-ocf-root=${PREFIX}/etc/ocf
INSTALL_TARGET=	install-strip

USERS=		hacluster
GROUPS=		haclient

OPTIONS_DEFINE=		DOCS DRAC3 HPI IPMI MANPAGES SNMP
OPTIONS_DEFAULT=	DRAC3 IPMI MANPAGES SNMP
OPTIONS_SUB=		yes

DRAC3_CONFIGURE_OFF=	ac_cv_header_curl_curl_h=no
DRAC3_DESC=		Dell DRAC III support
DRAC3_LIB_DEPENDS=	libcurl.so:ftp/curl

HPI_CONFIGURE_OFF=	ac_cv_header_openhpi_SaHpi_h=no
HPI_DESC=		SAF Hardware Platform Interface support
HPI_LIB_DEPENDS=	libopenhpi.so:sysutils/openhpi

IPMI_CONFIGURE_ENABLE=	ipmilan
IPMI_DESC=		Intelligent Platform Management Interface support
IPMI_LIB_DEPENDS=	libOpenIPMI.so:sysutils/openipmi

MANPAGES_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			help2man:misc/help2man \
			xsltproc:textproc/libxslt
MANPAGES_CONFIGURE_ENABLE=doc

SNMP_CONFIGURE_ENABLE=	snmp
SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp

.include <bsd.port.options.mk>

.if exists(${LOCALBASE}/include/vacmclient_api.h)
PLIST_SUB+=	VACM=""
.else
PLIST_SUB+=	VACM="@comment "
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/logd/logd.cf \
		${STAGEDIR}${PREFIX}/etc/ha_logd.cf.sample

.include <bsd.port.mk>
