# New ports collection makefile for:    lynx
# Date created:         15 Dec 1994
# Whom:                 Stefan `Sec` Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTNAME=	lynx-ssl
PORTVERSION=	2.8.3.1
CATEGORIES=	www
MASTER_SITES=	ftp://lynx.isc.org/current/
DISTNAME=	lynx2.8.3rel.1

USE_OPENSSL=	yes
USE_BZIP2=	yes

.include <bsd.port.pre.mk>

PATCH_SITES=	http://www.moxienet.com/lynx/
PATCHFILES=	lynx-283-ssl.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sec@42.org

GNU_CONFIGURE=	yes
CFLAGS+=	-I${OPENSSLINC}/openssl
CONFIGURE_ARGS=	--with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc" \
		--enable-nsl-fork
MAKEFILE=	makefile
INSTALL_TARGET=	install-full
MAN1=		lynx.1

WRKSRC=		${WRKDIR}/lynx2-8-3

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/lynx_help
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/lynx
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/etc/lynx.cfg

.include <bsd.port.post.mk>
