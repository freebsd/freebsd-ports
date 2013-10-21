# Created by: sten@blinkenlights.nl
# $FreeBSD$

PORTNAME=	ladvd
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	GOOGLE_CODE \
		http://blinkenlights.nl/software/ladvd/

MAINTAINER=	sten@blinkenlights.nl
COMMENT=	A minimal LLDP/CDP daemon

LICENSE=	BSD

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

USERS=		ladvd
GROUPS=		${USERS}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-chroot-dir=/var/empty

PORTDOCS=	*
MAN8=		ladvd.8 ladvdc.8
USE_RC_SUBR+=	ladvd
SUB_FILES=	pkg-message

PLIST_FILES=	sbin/ladvd \
		sbin/ladvdc

NO_STAGE=	yes
post-patch:
.if defined(NOPORTDOCS)
	@@${REINPLACE_CMD} 's|install-data-am: install-dist_docDATA|install-data-am:|' \
		${WRKSRC}/doc/Makefile.in
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
