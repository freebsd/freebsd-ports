# Created by: Dmitry Frolov <frol@nov.net>
# $FreeBSD$

PORTNAME=	ipmitool
PORTVERSION=	1.8.18
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	zi@FreeBSD.org
COMMENT=	CLI to manage IPMI systems

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe tar:bzip2 gmake readline ssl
CPE_VENDOR=	sun
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/ipmitool man/man1/ipmitool.1.gz man/man8/ipmievd.8.gz \
		sbin/ipmievd share/ipmitool/oem_ibm_sel_map \
		${PERIODIC_DIR}/400.status-ipmi
SUB_FILES=	status-ipmi.sh
PORTDOCS=	AUTHORS COPYING ChangeLog README

PERIODIC_DIR=	etc/periodic/daily

OPTIONS_DEFINE=	FREEIPMI DOCS
FREEIPMI_DESC=	Enable support for freeipmi

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

DOCS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-Makefile.in

FREEIPMI_LIB_DEPENDS=	libfreeipmi.so:sysutils/freeipmi
FREEIPMI_CPPFLAGS=	-I${LOCALBASE}/include
FREEIPMI_LDFLAGS=	-L${LOCALBASE}/lib
FREEIPMI_CONFIGURE_ENABLE=	intf-free

.include <bsd.port.options.mk>

.if (${OPSYS} == FreeBSD && ${OSVERSION} >= 1200085) || ${SSL_DEFAULT} == openssl
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-src_plugins_lanplus_lanplus__crypt__impl.c
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PERIODIC_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/status-ipmi.sh ${STAGEDIR}${PREFIX}/${PERIODIC_DIR}/400.status-ipmi

.include <bsd.port.mk>
