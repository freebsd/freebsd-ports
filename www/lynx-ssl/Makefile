# New ports collection makefile for:    lynx
# Version required:     2.8
# Date created:         15 Dec 1994
# Whom:                 Stefan `Sec` Zehl <sec@42.org>
#
# $Id$
#

DISTNAME=       lynx2.8.1rel.1
PKGNAME=        lynx-ssl-2.8.1.1
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/

.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
PATCH_SITES=	http://www.moxienet.com/lynx/
EXTRA_SSL_LIBS=	"-lRSAglue -lrsaref"
.else
PATCH_SITES=	ftp://ftp.musin.de/unix/
.endif
PATCHFILES=	lynx-281-ssl.patch.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	sec@42.org

BUILD_DEPENDS=	openssl:${PORTSDIR}/security/openssl

RESTRICTED=     "Contains cryptography"

GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc" \
		--enable-nsl-fork
MAKEFILE=       makefile
MAKE_ENV+=	EXTRA_SSL_LIBS=${EXTRA_SSL_LIBS}
INSTALL_TARGET= install install-help
MAN1=		lynx.1

WRKSRC=		${WRKDIR}/lynx2-8-1

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/lynx_help
	chown ${SHAREOWN}:${SHAREGRP} ${PREFIX}/etc/lynx.cfg

.include <bsd.port.mk>
