# Ports collection makefile for: sipxportlib
# Date created: Jan 8, 2007
# Whom: Michael Durian <durian@shadetreesoftware.com>
#
# $FreeBSD$
#

PORTNAME=	sipxportlib
PORTVERSION=	3.6.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.sipfoundry.org/pub/sipX/3.6/SRC/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	sipX library of general purpose utils and OS abstration APIs.

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre
BUILD_DEPENDS=	cppunit-config:${PORTSDIR}/devel/cppunit \
		ginstall:${PORTSDIR}/sysutils/coreutils
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

DEPRECATED=		old version, needs updating
EXPIRATION_DATE=	2009-03-27

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262:env automake:19:env
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PERL5_RUN=	yes
LOCALSTATEDIR=	/var
CONFIGURE_ENV+=	wwwdir=${PREFIX}/www/sipX \
		INSTALL=`which ginstall`
CONFIGURE_ARGS+=	--enable-sip-tls \
		--prefix=${PREFIX} \
		--localstatedir=${LOCALSTATEDIR}

post-patch:
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/sipx-upgrade-testsuite.in
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/sipx-upgrade.in

.include <bsd.port.mk>
