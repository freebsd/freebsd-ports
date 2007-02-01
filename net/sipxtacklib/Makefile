# Ports collection makefile for: sipxtacklib
# Date created: Jan 8, 2007
# Whom: Michael Durian <durian@shadetreesoftware.com>
#
# $FreeBSD$
#

PORTNAME=	sipxtacklib
PORTVERSION=	3.6.0
CATEGORIES=	net java
MASTER_SITES=	http://www.sipfoundry.org/pub/sipX/3.6/SRC/

MAINTAINER=	durian@shadetreesoftware.com
COMMENT=	sipX library of utilities and SIP stack info processing

LIB_DEPENDS=	sipXport:${PORTSDIR}/net/sipxportlib \
		pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash
BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		cppunit-config:${PORTSDIR}/devel/cppunit \
		ginstall:${PORTSDIR}/sysutils/coreutils \
		cppunit-config:${PORTSDIR}/devel/cppunit

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:259:env automake:19:env
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PERL5_RUN=	yes
USE_JAVA=	1.4+
LOCALSTATEDIR=${DESTDIR}/var
CONFIGURE_ENV+=	JAVA_HOME=${JAVA_HOME} \
		wwwdir=${PREFIX}/www/sipX \
		INSTALL=`which ginstall`
CONFIGURE_ARGS+=	--enable-sip-tls \
		--prefix=${PREFIX} \
		--localstatedir=${LOCALSTATEDIR}

post-patch:
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/siptest/src/siptest/subscribe-dialog-test
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/syslog2siptrace/merge-logs

.include <bsd.port.mk>
