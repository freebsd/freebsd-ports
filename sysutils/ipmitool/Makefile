PORTNAME=	ipmitool
PORTVERSION=	1.8.19
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	https://codeberg.org/IPMITool/${PORTNAME}/archive/:ipmi \
		LOCAL/zi/:iana
DISTFILES=	IPMITOOL_${PORTVERSION:S/./_/g}${EXTRACT_SUFX}:ipmi \
		enterprise-numbers-20240907.txt:iana
EXTRACT_ONLY=	IPMITOOL_${PORTVERSION:S/./_/g}${EXTRACT_SUFX}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	CLI to manage IPMI systems
WWW=		https://codeberg.org/IPMITool/ipmitool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool cpe gmake readline ssl
CPE_VENDOR=	sun
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
PLIST_FILES=	bin/ipmitool \
		share/man/man1/ipmitool.1.gz \
		share/man/man8/ipmievd.8.gz \
		sbin/ipmievd \
		share/ipmitool/oem_ibm_sel_map \
		share/ipmitool/enterprise-numbers \
		${PERIODIC_DIR}/400.status-ipmi
SUB_FILES=	status-ipmi.sh
PORTDOCS=	AUTHORS COPYING ChangeLog README

PERIODIC_DIR=	etc/periodic/daily

OPTIONS_DEFINE=	FREEIPMI DOCS
FREEIPMI_DESC=	Enable support for freeipmi

WRKSRC=		${WRKDIR}/${PORTNAME}

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

.if defined(WITH_DEBUG)
CFLAGS+=	-ggdb -Wall
.endif

.if exists(/usr/include/sys/ipmi.h)
CONFIGURE_ARGS+=	--enable-intf-open
.else
CONFIGURE_ARGS+=	--disable-intf-open
.endif

CONFIGURE_ARGS+=	IANADIR=${DATADIR}
DOCS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-Makefile.in

FREEIPMI_LIB_DEPENDS=	libfreeipmi.so:sysutils/freeipmi
FREEIPMI_CPPFLAGS=	-I${LOCALBASE}/include
FREEIPMI_LDFLAGS=	-L${LOCALBASE}/lib
FREEIPMI_CONFIGURE_ENABLE=	intf-free

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PERIODIC_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/status-ipmi.sh \
		${STAGEDIR}${PREFIX}/${PERIODIC_DIR}/400.status-ipmi
	${INSTALL_DATA} ${DISTDIR}/enterprise-numbers-20240907.txt \
		${STAGEDIR}${DATADIR}/enterprise-numbers
.include <bsd.port.mk>
