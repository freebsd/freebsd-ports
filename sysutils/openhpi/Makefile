# $FreeBSD$

PORTNAME=	openhpi
PORTVERSION=	3.6.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/openhpi/openhpi-stable/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hardware Platform Interface implementation

LICENSE=	OPENHPI
LICENSE_NAME=	OpenHPI license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid \
		libnetsnmp.so:net-mgmt/net-snmp \
		libgcrypt.so:security/libgcrypt

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USES=		gmake gnome libtool pathfix perl5 pkgconfig shebangfix
SHEBANG_FILES=	plugins/snmp_bc/eventmap2code.pl scripts/text2cstr.pl
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_PERL5=	build
USE_RC_SUBR=	openhpid

post-patch:
	@${REINPLACE_CMD} 's/-lstdc++//' \
		${WRKSRC}/baselib/Makefile.in \
		${WRKSRC}/openhpid/Makefile.in \
		${WRKSRC}/plugins/dynamic_simulator/Makefile.in \
		${WRKSRC}/plugins/ipmidirect/Makefile.in
	@${REINPLACE_CMD} '/XML2_INCLUDE=/s|=.*|=-I${LOCALBASE}/include/libxml2|' \
		${WRKSRC}/configure

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/openhpi.conf \
		${STAGEDIR}${ETCDIR}/openhpi.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/openhpiclient.conf \
		${STAGEDIR}${ETCDIR}/openhpiclient.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/simulation.data \
		${STAGEDIR}${ETCDIR}/simulation.data.sample

.include <bsd.port.mk>
