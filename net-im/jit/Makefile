# New ports collection makefile for:    jit
# Date created:                 20 July 2004
# Whom:                         Alexander Timoshenko <gonzo@univ.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	jit
PORTVERSION=	1.1.6
CATEGORIES=	net
MASTER_SITES=	http://www.jabberstudio.org/files/jit/
DIST_SUBDIR=	jabber

MAINTAINER=	gonzo@univ.kiev.ua
COMMENT=	Jabber ICQ Transport

USE_GMAKE=	yes
USE_REINPLACE=  yes
HAS_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/jit/jabber-icq.example ${WRKSRC}/jit/jit.sh

do-install:
	@${MKDIR} ${PREFIX}/lib/jabber/jit
	@${INSTALL_DATA} ${WRKSRC}/jit/jit.so ${PREFIX}/lib/jabber/jit
	@${INSTALL_DATA} ${WRKSRC}/xdb_file/xdb_file.so ${PREFIX}/lib/jabber/jit
	@${INSTALL_PROGRAM} ${WRKSRC}/jabberd/jabberd  ${PREFIX}/sbin/jit
	@${INSTALL_DATA} ${WRKSRC}/jit/jabber-icq.example ${PREFIX}/etc
	@${INSTALL_SCRIPT} ${WRKSRC}/jit/jit.sh  ${PREFIX}/etc/rc.d

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
