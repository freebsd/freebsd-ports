# Created by: sten@blinkenlights.nl
# $FreeBSD$

PORTNAME=	ladvd
PORTVERSION=	1.0.4
CATEGORIES=	net
MASTER_SITES=	GOOGLE_CODE \
		http://blinkenlights.nl/software/ladvd/

MAINTAINER=	sten@blinkenlights.nl
COMMENT=	Minimal LLDP/CDP daemon

LICENSE=	BSD

LIB_DEPENDS=	libevent-1.4.so:${PORTSDIR}/devel/libevent

USERS=		ladvd
GROUPS=		${USERS}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-chroot-dir=/var/empty

PORTDOCS=	*
USE_RC_SUBR=	ladvd
SUB_FILES=	pkg-message

PLIST_FILES=	man/man8/ladvd.8.gz \
		man/man8/ladvdc.8.gz \
		sbin/ladvd \
		sbin/ladvdc

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@@${REINPLACE_CMD} 's|install-data-am: install-dist_docDATA|install-data-am:|' \
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
