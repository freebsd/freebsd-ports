# New ports collection makefile for:	sslh
# Date created:		2010-03-29
# Whom:			Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	sslh
PORTVERSION=	1.7a
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.rutschle.net/tech/

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	A ssl/ssh multiplexer

USE_GMAKE=	yes
USE_PERL5_BUILD=	yes

.if !defined(NO_INSTALL_MANPAGES)
MAN8=		sslh.8
.endif
PLIST_FILES=	sbin/sslh

USE_RC_SUBR=	sslh

post-patch:
	@${REINPLACE_CMD} -e 's|^PREFIX=/usr/local|PREFIX=${PREFIX}|g' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/sslh ${PREFIX}/sbin
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${WRKSRC}/sslh.8 ${MANPREFIX}/man/man8
.endif

.include <bsd.port.mk>
