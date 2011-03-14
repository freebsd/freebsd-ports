# New ports collection makefile for:    jit
# Date created:                 20 July 2004
# Whom:                         Alexander Timoshenko <gonzo@univ.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	jit
PORTVERSION=	1.1.7
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://www.penza-gsm.ru/snake/xmpp/
DIST_SUBDIR=	jabber

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jabber ICQ Transport

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_GMAKE=	yes
USE_RC_SUBR=	jabber_jit.sh
HAS_CONFIGURE=	yes
CFLAGS+=	-fPIC
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/jit/jabber-icq.example

do-install:
	@${MKDIR} ${PREFIX}/lib/jabber/jit
	@${INSTALL_DATA} ${WRKSRC}/jit/jit.so ${PREFIX}/lib/jabber/jit
	@${INSTALL_DATA} ${WRKSRC}/xdb_file/xdb_file.so ${PREFIX}/lib/jabber/jit
	@${INSTALL_PROGRAM} ${WRKSRC}/jabberd/jabberd-jit  ${PREFIX}/sbin/jit
	@${INSTALL_DATA} ${WRKSRC}/jit/jabber-icq.example ${PREFIX}/etc

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
