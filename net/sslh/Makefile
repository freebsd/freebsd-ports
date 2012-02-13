# New ports collection makefile for:	sslh
# Date created:		2010-03-29
# Whom:			Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	sslh
PORTVERSION=	1.10
CATEGORIES=	net
MASTER_SITES=	http://www.rutschle.net/tech/

MAINTAINER=	olivier@cochard.me
COMMENT=	A ssl/ssh multiplexer

USE_GMAKE=	yes
USE_PERL5_BUILD=	yes

.if !defined(NO_INSTALL_MANPAGES)
MAN8=		sslh.8
.endif

VARDIR=		/var
PLIST_SUB=	VARDIR=${VARDIR}

USE_RC_SUBR=	sslh

post-patch:
	@${REINPLACE_CMD} -e 's|^PREFIX=/usr/local|PREFIX=${PREFIX}|g' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/sslh-fork ${PREFIX}/sbin
	@${INSTALL_PROGRAM} ${WRKSRC}/sslh-select ${PREFIX}/sbin
	@${MKDIR} ${VARDIR}/run/${PORTNAME}
	@${CHOWN} -R nobody:nobody ${VARDIR}/run/${PORTNAME}
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${WRKSRC}/sslh.8 ${MANPREFIX}/man/man8
.endif

.include <bsd.port.mk>
