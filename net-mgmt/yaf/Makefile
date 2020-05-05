# Created by: Dikshie <dikshie@sfc.wide.ad.jp>
# $FreeBSD$

PORTNAME=	yaf
PORTVERSION=	2.11.0
CATEGORIES=	net-mgmt
MASTER_SITES=	http://tools.netsa.cert.org/releases/

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	YAF is Yet Another Flowmeter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfixbuf.so:net/libfixbuf \
		libltdl.so:devel/libltdl \
		libpcap.so:net/libpcap \
		libpcre.so:devel/pcre

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gnome libtool pathfix perl5 pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--sysconfdir="${ETCDIR}"

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	PAYLOAD APPLABEL PLUGIN FPEXPORT ENTROPY MPLS NONIP IFEXP CMPTIP4 LOCALTIME DNSAUTH DNSNX
OPTIONS_DEFAULT=	PAYLOAD APPLABEL PLUGIN ENTROPY
OPTIONS_SUB=	yes

PAYLOAD_DESC=	YAF will enable reading past IP headers to do deep packet inspection
APPLABEL_DESC=	Create protocol application labels via traffic header inspection.
PLUGIN_DESC=	Enable YAF plugins, primary for application labeling.
FPEXPORT_DESC=	Export of OS fingerprinting information, e.g. p0f.
ENTROPY_DESC=	Generate Shannon entropy values of the data stream.
MPLS_DESC=	MPLS capture and export
NONIP_DESC=	Capture non-IP packets
IFEXP_DESC=	Export capture interface for DAG/Napatech/Netronome cards.
CMPTIP4_DESC=	Create compact IPv4 output (no IPv6 support).
LOCALTIME_DESC=	Allow localtime to be used for command inputs and record printing. Flow records are always in UTC.
DNSAUTH_DESC=	Modify DNS export to only export Authoritative DNS responses.
DNSNX_DESC=	Modify DNS export to only export NXDomain responses.

PAYLOAD_CONFIGURE_ENABLE=	payload
APPLABEL_CONFIGURE_ENABLE=	applabel
PLUGIN_CONFIGURE_ENABLE=	plugins
FPEXPORT_CONFIGURE_ENABLE=	fpexporter
ENTROPY_CONFIGURE_ENABLE=	entropy
MPLS_CONFIGURE_ENABLE=	mpls
NONIP_CONFIGURE_ENABLE=	nonip
IFEXP_CONFIGURE_ENABLE=	interface
CMPTIP4_CONFIGURE_ENABLE=	compact-ip4
LOCALTIME_CONFIGURE_ENABLE=	localtime
DNSAUTH_CONFIGURE_ENABLE=	exportDNSAuth
DNSNX_CONFIGURE_ENABLE=	exportDNSNXDomain

APPLABEL_IMPLIES=	PAYLOAD
DNSAUTH_IMPLIES=	PLUGIN APPLABEL
DNSNX_IMPLIES=		PLUGIN APPLABEL
ENTROPY_IMPLIES=	PAYLOAD
NONIP_IMPLIES=		MPLS

.include <bsd.port.options.mk>

.if defined(WITH_DAG)
CONFIGURE_ARGS+=	--with-dag=${LOCALBASE}
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/yaf
.for f in dhcp_fingerprints.conf yafApplabelRules.conf yafDPIRules.conf yaf.conf
	${MV} ${STAGEDIR}${PREFIX}/etc/yaf/$f ${STAGEDIR}${PREFIX}/etc/yaf/$f.sample
.endfor
	${RM} ${STAGEDIR}${PREFIX}/etc/p0f.fp

.include <bsd.port.mk>
