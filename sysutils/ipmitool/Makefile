# New ports collection makefile for:	ipmitool
# Date created:				25/Oct/2004
# Whom:					Dmitry Frolov <frol@nov.net>
#
# $FreeBSD$
#

PORTNAME=	ipmitool
PORTVERSION=	1.8.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	frolov@riss-telecom.ru
COMMENT=	CLI to manage IPMI systems

USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_AUTOTOOLS=	autoconf:259 libtool:15 aclocal:19 automake:19
# libtool15 installs it's aclocal macros into ${LOCALBASE}/share/aclocal
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--enable-intf-lan --enable-intf-lanplus \
		--disable-intf-imb --disable-intf-lipmi --disable-intf-bmc \
		${OPENIPMI_OPT}
PLIST_FILES=	bin/ipmitool sbin/ipmievd
PLIST_DIRS=	share/${PORTNAME}
PORTDOCS=	README AUTHORS ChangeLog COPYING
MAN1+=		${PORTNAME}.1
MAN8+=		ipmievd.8

DATAFILES=	bmclanconf ipmi.init.basic ipmi.init.redhat README \
		collect_data.sh create_rrds.sh create_webpage_compact.sh \
		create_webpage.sh
.for f in ${DATAFILES}
PLIST_FILES+=	share/${PORTNAME}/${f}
.endfor

.include <bsd.port.pre.mk>

# Silence automake about missing files
pre-configure:
	@${TOUCH} ${WRKSRC}/NEWS ${WRKSRC}/INSTALL

# FreeBSD has OpenIPMI-compatible driver, ipmi(4),
# in 7-current after 2006-02-12. On older systems
# only lan and lanplus interfaces are supported.
.if exists(/usr/include/sys/ipmi.h)
OPENIPMI_OPT=	--enable-intf-open
.else
OPENIPMI_OPT=	--disable-intf-open
.endif

.include <bsd.port.post.mk>
