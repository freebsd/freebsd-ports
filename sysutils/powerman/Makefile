PORTNAME=	powerman
DISTVERSION=	2.4.4
CATEGORIES=	sysutils parallel
MASTER_SITES=	https://github.com/chaos/${PORTNAME}/releases/download/v${DISTVERSION}/

PATCH_SITES=	https://github.com/chaos/${PORTNAME}/commit/
PATCHFILES=	4780df0aa1d2a716fb39b225074da3c98c3443f1.patch:-p1 \
		8fbc1a13e34c656114c91ee6a51483b959e65039.patch:-p1 \
		2022d263125a1e68e3ee66e5cf47dbc0ab851e6e.patch:-p1 \
		b2b57b5cb63f68d19c8504221099214e8c81c09a.patch:-p1 \
		3495907fa11712b81db0008c9befc513e2d33d27.patch:-p1 \
		457f95a4be7bd5c3c819baa3ef95917dacb4ef0c.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for doing remote power control
WWW=		https://github.com/chaos/powerman

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjansson.so:devel/jansson \
		libnetsnmp.so:net-mgmt/net-snmp
TEST_DEPENDS=	bash:shells/bash \
		valgrind:devel/valgrind

USES=		libtool localbase perl5 shebangfix
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_RC_SUBR=	${PORTNAME}
SHEBANG_FILES=	heartbeat/powerman
bash_CMD=	${SH}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-httppower --localstatedir=/var
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

post-install:
	${RM} ${STAGEDIR}${PREFIX}/powerman.service

pre-test:
	# fix hardcoded linuxism
	${REINPLACE_CMD} 's|stat -c%s |stat -f%z |' ${WRKSRC}/t/t0005-telemetry.t
	${REINPLACE_CMD} 's|/bin/bash|${LOCALBASE}/bin/bash|' ${WRKSRC}/t/scripts/pm-sim.sh
	${CP} ${FILESDIR}/valgrind.supp ${WRKSRC}/t/etc

.include <bsd.port.mk>
