# New ports collection makefile for:	ladvd
# Date Created:				27 Jul 2008
# Whom:					sten@blinkenlights.nl
#
# $FreeBSD$
#

PORTNAME=	ladvd
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://blinkenlights.nl/software/ladvd/

MAINTAINER=	sten@blinkenlights.nl
COMMENT=	A minimal CDP/LLDP daemon

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-chroot-dir=/var/empty

PORTDOCS=	*
MAN8=		ladvd.8 ladvdc.8
USE_RC_SUBR+=	ladvd
SUB_FILES=	pkg-message pkg-install

post-patch:
.if defined(NOPORTDOCS)
	@@${REINPLACE_CMD} 's|install-data-am: install-dist_docDATA|install-data-am:|' \
		${WRKSRC}/doc/Makefile.in
.endif

post-install:
	@${ECHO} "==>  Creating custom user to run ladvd..."
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
