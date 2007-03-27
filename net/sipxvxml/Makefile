# Ports collection makefile for: sipxvxml
# Date created: Jan 8, 2007
# Whom: Michael Durian <durian@shadetreesoftware.com>
#
# $FreeBSD$
#

PORTNAME=	sipxvxml
PORTVERSION=	3.6.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.sipfoundry.org/pub/sipX/3.6/SRC/

MAINTAINER=	durian@shadetreesoftware.com
COMMENT=	sipX server for managing XML files

BUILD_DEPENDS=	ginstall:${PORTSDIR}/sysutils/coreutils
LIB_DEPENDS=	sipXport:${PORTSDIR}/net/sipxportlib \
		sipXtack:${PORTSDIR}/net/sipxtacklib \
		sipXmedia:${PORTSDIR}/net/sipxmedialib \
		sipXmediaProcessing:${PORTSDIR}/net/sipxmediaadapterlib \
		sipXcall:${PORTSDIR}/net/sipxcalllib \
		wwwssl:${PORTSDIR}/www/libwww \
		xerces-c:${PORTSDIR}/textproc/xerces-c2 \
		pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:259:env automake:19:env
GNU_CONFIGURE=	yes
LOCALSTATEDIR=${DESTDIR}/var
CONFIGURE_ENV+=	wwwdir=${PREFIX}/www/sipX \
		INSTALL=`which ginstall`
CONFIGURE_ARGS+=	--enable-sip-tls \
		--prefix=${PREFIX} \
		--localstatedir=${LOCALSTATEDIR}
SUB_LIST=	LOCALSTATEDIR=${LOCALSTATEDIR} \
		PREFIX=${PREFIX}
SUB_FILES=	pkg-install pkg-deinstall
PKGINSTALL=	${WRKDIR}/pkg-install

post-patch:
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/sipXvxml.sh.in

pre-install:
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install:
	@${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL

.include <bsd.port.mk>
