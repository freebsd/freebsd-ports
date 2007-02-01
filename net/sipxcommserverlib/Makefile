# Ports collection makefile for: sipxcommserverlib
# Date created: Jan 8, 2007
# Whom: Michael Durian <durian@shadetreesoftware.com>
#
# $FreeBSD$
#

PORTNAME=	sipxcommserverlib
PORTVERSION=	3.6.0
CATEGORIES=	net
MASTER_SITES=	http://www.sipfoundry.org/pub/sipX/3.6/SRC/

MAINTAINER=	durian@shadetreesoftware.com
COMMENT=	sipX library for communications between components

LIB_DEPENDS=	sipXport:${PORTSDIR}/net/sipxportlib \
		sipXtack:${PORTSDIR}/net/sipxtacklib \
		wwwssl:${PORTSDIR}/www/libwww \
		xerces-c:${PORTSDIR}/textproc/xerces-c2 \
		odbc:${PORTSDIR}/databases/unixODBC \
		pcre.0:${PORTSDIR}/devel/pcre
BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed \
		ginstall:${PORTSDIR}/sysutils/coreutils \
		cppunit-config:${PORTSDIR}/devel/cppunit
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		postmaster:${PORTSDIR}/databases/postgresql81-server

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:259:env automake:19:env
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PERL5_RUN=	yes
LOCALSTATEDIR=${DESTDIR}/var
CONFIGURE_ENV+=	wwwdir=${PREFIX}/www/sipX \
		INSTALL=`which ginstall`
CONFIGURE_ARGS+=	--enable-sip-tls \
		--prefix=${PREFIX} \
		--localstatedir=${LOCALSTATEDIR}
SUB_LIST=	LOCALSTATEDIR=${LOCALSTATEDIR}
SUB_FILES=	pkg-deinstall

post-patch:
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/configpp
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/sipx-validate-xml.in
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/bin/pgpatch.sh
	@${REINPLACE_CMD} -e "s,@PREFIX@,${PREFIX}," ${WRKSRC}/bin/pgpatch.sh
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/src/sipdbtest/sipdbtest.sh.in

.include <bsd.port.mk>
