# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openvswitch
PORTVERSION=	2.3.3
CATEGORIES=	net
MASTER_SITES=	http://openvswitch.org/releases/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Production quality, multilayer virtual switch

LICENSE=	APACHE20

BROKEN_powerpc64=	fails to compile: bfd.c: internal compiler error: in extract_insn, at recog.c

USES=		cpe gmake libtool perl5 pkgconfig python shebangfix ssl
SHEBANG_FILES=	vtep/ovs-vtep
USE_LDCONFIG=   yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --localstatedir=/var \
		--with-dbdir=/var/db/${PORTNAME} \
		--with-openssl=${OPENSSLBASE}
USE_RC_SUBR=	ovs-vswitchd ovsdb-server
LDFLAGS+=	-lpthread

post-install:
	${INSTALL_DATA} ${WRKSRC}/vswitchd/vswitch.ovsschema ${STAGEDIR}${PREFIX}/share/openvswitch/

.include <bsd.port.mk>
