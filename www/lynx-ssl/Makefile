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

.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
PATCH_SITES=	http://www.moxienet.com/lynx/
EXTRA_SSL_LIBS=	"-lRSAglue -lrsaref"
.else
PATCH_SITES=	ftp://ftp.musin.de/unix/
.endif
PATCHFILES=	lynx-282-ssl.patch.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	sec@42.org

BUILD_DEPENDS=	openssl:${PORTSDIR}/security/openssl
LIB_DEPENDS=	crypto.1:${PORTSDIR}/security/openssl \
		ssl.1:${PORTSDIR}/security/openssl

RESTRICTED=     "Contains cryptography"

GNU_CONFIGURE=  YES
CFLAGS+=	-I${PREFIX}/include/openssl
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc" \
		--enable-nsl-fork
MAKEFILE=       makefile
MAKE_ENV+=	EXTRA_SSL_LIBS=${EXTRA_SSL_LIBS}
INSTALL_TARGET= install install-help
MAN1=		lynx.1

WRKSRC=		${WRKDIR}/lynx2-8-2

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/lynx_help
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/etc/lynx.cfg

.include <bsd.port.mk>
