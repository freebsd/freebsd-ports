# Created by: Dikshie <dikshie@sfc.wide.ad.jp>
# $FreeBSD$

PORTNAME=	yaf
PORTVERSION=	2.9.3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://tools.netsa.cert.org/releases/

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	YAF is Yet Another Flowmeter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfixbuf.so:net/libfixbuf \
		libltdl.so:devel/libltdl \
		libpcre.so:devel/pcre

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pathfix perl5 pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	PAYLOAD APPLABEL PLUGIN FPEXPORT ENTROPY MPLS NONIP P0FPRINT IFEXP CMPTIP4 LOCALTIME DNSAUTH DNSNX
OPTIONS_DEFAULT=	PAYLOAD APPLABEL PLUGIN ENTROPY
OPTIONS_SUB=	yes

PAYLOAD_DESC=	YAF will enable reading past IP headers to do deep packet inspection
APPLABEL_DESC=	Create protocol application labels via traffic header inspection.
PLUGIN_DESC=	Enable YAF plugins, primary for application labeling.
FPEXPORT_DESC=	Export of OS fingerprinting information, e.g. p0f.
ENTROPY_DESC=	Generate Shannon entropy values of the data stream.
MPLS_DESC=	MPLS capture and export
NONIP_DESC=	Capture non-IP packets
P0FPRINT_DESC=	Generate p0f O/S fingerprinting.
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
P0FPRINT_CONFIGURE_ENABLE=	p0fprinter
IFEXP_CONFIGURE_ENABLE=	interface
CMPTIP4_CONFIGURE_ENABLE=	compact-ip4
LOCALTIME_CONFIGURE_ENABLE=	localtime
DNSAUTH_CONFIGURE_ENABLE=	exportDNSAuth
DNSNX_CONFIGURE_ENABLE=	exportDNSNXDomain

APPLABEL_IMPLIES=	PAYLOAD
DNSAUTH_IMPLIES=	PLUGIN APPLABEL
DNSNX_IMPLIES=		PLUGIN APPLABEL
ENTROPY_IMPLIES=	PAYLOAD
P0FPRINT_IMPLIES=	APPLABEL
NONIP_IMPLIES=		MPLS

P0FPRINT_LIB_DEPENDS=	libp0f.so:net/libp0f

.include <bsd.port.options.mk>

.if defined(WITH_DAG)
CONFIGURE_ARGS+=	--with-dag=${LOCALBASE}
LIB_DEPENDS+=	libpcap.so.1:net/libpcap
.elif exists(${LOCALBASE}/lib/libpcap.so)
LIB_DEPENDS+=	libpcap.so.1:net/libpcap
.endif

post-install:
.for f in dhcp_fingerprints.conf yafApplabelRules.conf yafDPIRules.conf
	${MV} ${STAGEDIR}${PREFIX}/etc/$f ${STAGEDIR}${PREFIX}/etc/$f.sample
.endfor
	${RM} ${STAGEDIR}${PREFIX}/etc/p0f.fp

.include <bsd.port.mk>
