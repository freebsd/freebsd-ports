# Ports collection makefile for: sipxproxy
# Date created: Jan 8, 2007
# Whom: Michael Durian <durian@shadetreesoftware.com>
#
# $FreeBSD$
#

PORTNAME=	sipxproxy
PORTVERSION=	3.6.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.sipfoundry.org/pub/sipX/3.6/SRC/

MAINTAINER=	durian@shadetreesoftware.com
COMMENT=	sipX server for handling SIP authorization and call records

LIB_DEPENDS=	sipXport:${PORTSDIR}/net/sipxportlib \
		sipXtack:${PORTSDIR}/net/sipxtacklib \
		sipXcommserver:${PORTSDIR}/net/sipxcommserverlib \
		pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		psql:${PORTSDIR}/databases/postgresql81-client
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		gem:${PORTSDIR}/devel/ruby-gems \
		rake:${PORTSDIR}/devel/rubygem-rake \
		ginstall:${PORTSDIR}/sysutils/coreutils \
		cppunit-config:${PORTSDIR}/devel/cppunit

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_RUBY=	yes
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
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/sipxcallresolver.sh.in
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/sipproxy.sh.in
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/sipauthproxy.sh.in
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/sipxha-distrib.sh.in

pre-install:
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install:
	@${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL

.include <bsd.port.mk>
