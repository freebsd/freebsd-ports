# New ports collection makefile for:    jit
# Date created:                 20 July 2004
# Whom:                         Alexander Timoshenko <gonzo@univ.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	jit
PORTVERSION=	1.1.7
CATEGORIES=	net
MASTER_SITES=	http://www.penza-gsm.ru/snake/xmpp/
DIST_SUBDIR=	jabber

MAINTAINER=	alexander.timoshenko@gmail.com
COMMENT=	Jabber ICQ Transport

USE_GMAKE=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "amd64"
BROKEN=		"Does not build on amd64 or ia64"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/jit/jabber-icq.example ${WRKSRC}/jit/jit.sh

do-install:
	@${MKDIR} ${PREFIX}/lib/jabber/jit
	@${INSTALL_DATA} ${WRKSRC}/jit/jit.so ${PREFIX}/lib/jabber/jit
	@${INSTALL_DATA} ${WRKSRC}/xdb_file/xdb_file.so ${PREFIX}/lib/jabber/jit
	@${INSTALL_PROGRAM} ${WRKSRC}/jabberd/jabberd-jit  ${PREFIX}/sbin/jit
	@${INSTALL_DATA} ${WRKSRC}/jit/jabber-icq.example ${PREFIX}/etc
	@${INSTALL_SCRIPT} ${WRKSRC}/jit/jit.sh  ${PREFIX}/etc/rc.d

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
