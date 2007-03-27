# Ports collection makefile for: sipxconfig
# Date created: Jan 8, 2007
# Whom: Michael Durian <durian@shadetreesoftware.com>
#
# $FreeBSD$
#

PORTNAME=	sipxconfig
PORTVERSION=	3.6.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.sipfoundry.org/pub/sipX/3.6/SRC/

MAINTAINER=	durian@shadetreesoftware.com
COMMENT=	sipX server for configuring sipX via a web interface

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit \
		gem:${PORTSDIR}/devel/ruby-gems \
		rake:${PORTSDIR}/devel/rubygem-rake \
		zip:${PORTSDIR}/archivers/zip \
		ginstall:${PORTSDIR}/sysutils/coreutils
LIB_DEPENDS=	sipXport:${PORTSDIR}/net/sipxportlib \
		sipXtack:${PORTSDIR}/net/sipxtacklib \
		sipXcommserver:${PORTSDIR}/net/sipxcommserverlib \
		pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		psql:${PORTSDIR}/databases/postgresql81-client

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:259:env automake:19:env
USE_JAVA=	1.4+
USE_APACHE=	2.0+
USE_RUBY=	yes
GNU_CONFIGURE=	yes
LOCALSTATEDIR=${DESTDIR}/var
CONFIGURE_ENV+=	JAVA_HOME=${JAVA_HOME} \
		wwwdir=${PREFIX}/www/sipX \
		INSTALL=`which ginstall`
CONFIGURE_ARGS+=	--enable-sip-tls \
		--prefix=${PREFIX} \
		--localstatedir=${LOCALSTATEDIR} \
		--enable-ruby-bindings
SUB_LIST=	LOCALSTATEDIR=${LOCALSTATEDIR} \
		PREFIX=${PREFIX}
SUB_FILES=	pkg-install pkg-deinstall

PKGINSTALL=	${WRKDIR}/pkg-install

post-patch:
	@${REINPLACE_CMD} -e "s,/bin/bash,${PREFIX}/bin/bash," ${WRKSRC}/web/bin/sipxconfig.sh.in
	@${REINPLACE_CMD} -e "s,@PREFIX@,${PREFIX}," ${WRKSRC}/web/bin/sipxconfig.sh.in

pre-install:
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install:
	@${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL

.include <bsd.port.mk>
