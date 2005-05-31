# New ports collection makefile for:	ipmitool
# Date created:				25/Oct/2004
# Whom:					Dmitry Frolov <frol@nov.net>
#
# $FreeBSD$
#

PORTNAME=	ipmitool
PORTVERSION=	1.8.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	frolov@riss-telecom.ru
COMMENT=	CLI to manage IPMI systems

USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
# On FreeBSD only lan and lanplus interfaces are supported at this time
CONFIGURE_ARGS+=	--enable-intf-lan --enable-intf-lanplus \
		--disable-intf-open --disable-intf-imb --disable-intf-lipmi
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

.include <bsd.port.mk>
