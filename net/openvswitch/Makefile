# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openvswitch
PORTVERSION=	1.7.1
CATEGORIES=	net
MASTER_SITES=	http://openvswitch.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Production quality, multilayer virtual switch

LICENSE=	APACHE20

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	PERL=${PREFIX}/bin/perl \
		SSL_CFLAGS="-I${OPENSSLINC}" \
		SSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
USES=		gmake pkgconfig
USE_AUTOTOOLS=	autoconf automake
USE_OPENSSL=	yes
USE_PYTHON=	yes
USE_RC_SUBR=	ovs-vswitchd ovsdb-server

OPTIONS_DEFINE=	THREADED
THREADED_DESC=	Experimental high-performance threading patch

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTHREADED}
CONFIGURE_ARGS+=--enable-threaded=yes
.endif

AUTOTOOLSFILES=	aclocal.m4

post-patch:
	@${REINPLACE_CMD} -e 's|1.11.3|%%AUTOMAKE_APIVER%%|g' \
			  -e 's|2.68|%%AUTOCONF_VERSION%%|g' \
			  ${WRKSRC}/aclocal.m4
.if ${PORT_OPTIONS:MTHREADED}
	@# We can't use EXTRA_PATCHES, since we need to apply this one
	@# after files/patch-bsd-netdef.diff, not before.
	${PATCH} ${PATCH_ARGS} < ${FILESDIR}/threaded.diff
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/vswitchd/vswitch.ovsschema ${STAGEDIR}${PREFIX}/share/openvswitch/

#regression-test: build
#	@cd ${WRKSRC} && ${MAKE_CMD} check

.include <bsd.port.post.mk>
