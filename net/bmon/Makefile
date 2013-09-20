# Created by: Jon Nistor <nistor@snickers.org>
# $FreeBSD$

PORTNAME=	bmon
PORTVERSION=	2.1.0
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://people.suug.ch/~tgr/bmon/files/

MAINTAINER=	nistor@snickers.org
COMMENT=	Portable bandwidth monitor and rate estimator

OPTIONS_DEFINE=		DBI RRDTOOL
OPTIONS_DEFAULT=	DBI
DBI_DESC=	LibDBI output module for rsyslog
RRDTOOL_DESC=	Usage graphs support

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-asound
USE_GMAKE=	YES
MAKEFILE=	GNUmakefile

MAN1=		bmon.1
PLIST_FILES=	sbin/bmon

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRRDTOOL}
BUILD_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool
.else
CONFIGURE_ARGS+=--disable-rrd
.endif

.if ${PORT_OPTIONS:MDBI}
LIB_DEPENDS=	dbi.1:${PORTSDIR}/databases/libdbi
.else
CONFIGURE_ARGS+=--disable-dbi
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/bmon ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/bmon.1 ${PREFIX}/man/man1/bmon.1

.include <bsd.port.mk>
