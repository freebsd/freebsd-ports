# New ports collection makefile for:    lynx
# Version required:     2.8
# Date created:         15 Dec 1994
# Whom:                 Stefan `Sec` Zehl <sec@42.org>
#
# $FreeBSD$
#

DISTNAME=       lynx2.8.2rel.1
PKGNAME=        lynx-ssl-2.8.2.1
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/

USE_OPENSSL=	RSA
FORBIDDEN=	"Riddled with buffer overflows exploitable by a malicious server to execute code as the local user"

.include <bsd.port.pre.mk>

.if defined(OPENSSL_RSAREF)
PATCH_SITES=	http://www.moxienet.com/lynx/
.else
PATCH_SITES=	ftp://ftp.musin.de/unix/
.endif
PATCHFILES=	lynx-282-ssl.patch.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	sec@42.org

GNU_CONFIGURE=  YES
CFLAGS+=	-I${OPENSSLINC}/openssl
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc" \
		--enable-nsl-fork
MAKEFILE=       makefile
INSTALL_TARGET= install install-help
MAN1=		lynx.1

WRKSRC=		${WRKDIR}/lynx2-8-2

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/lynx_help
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/etc/lynx.cfg

.include <bsd.port.post.mk>
