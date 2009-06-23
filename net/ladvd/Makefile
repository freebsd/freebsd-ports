# New ports collection makefile for:	ladvd
# Date Created:				27 Jul 2008
# Whom:					sten@blinkenlights.nl
#
# $FreeBSD$
#

PORTNAME=	ladvd
PORTVERSION=	0.8
CATEGORIES=	net
MASTER_SITES=	http://blinkenlights.nl/software/ladvd/

MAINTAINER=	sten@blinkenlights.nl
COMMENT=	A minimal CDP/LLDP sender

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

ONLY_FOR_ARCHS=	i386

GNU_CONFIGURE=	yes

PORTDOCS=	*
MAN8=		ladvd.8
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
