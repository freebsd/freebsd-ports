# New ports collection makefile for:	hearbeat
# Date created:				18 March 2005
# Whom:					Scott Kleihege <scott-ports@tummy.com>
#
# $FreeBSD$
#

PORTNAME=	heartbeat
PORTVERSION=	1.2.3
CATEGORIES=	sysutils
MASTER_SITES=	http://linux-ha.org/download/

MAINTAINER=	scott-ports@tummy.com
COMMENT=	Subsystem for High-Availability Clustering

BUILD_DEPENDS=	${LOCALBASE}/include/libnet.h:${PORTSDIR}/net/libnet-devel

USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	glib12
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_INC_LIBTOOL_VER=	13
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--disable-fatal-warnings

SUB_FILES=	pkg-install

PKGDEINSTALL=	${PKGINSTALL}

MAN1=		cl_status.1
MAN8=		apphbd.8 heartbeat.8 ldirectord.8 meatclient.8 \
		stonith.8 supervise-ldirectord-config.8

post-patch:
	${REINPLACE_CMD} -e "s#logrotate.d##"	${WRKSRC}/heartbeat/Makefile.in	\
						${WRKSRC}/ldirectord/Makefile.in

post-deinstall:
	@${SH} ${PKGINSTALL} ${PKGNAME} DEINSTALL

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
