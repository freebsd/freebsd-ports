# New ports collection makefile for:    lynx
# Version required:     2.8.3*
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=       lynx2.8.3dev.20
PKGNAME=        lynx-2.8.3dev.20
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/

MAINTAINER=	ache@FreeBSD.org

FORBIDDEN=	"Riddled with buffer overflows exploitable by a malicious server to execute code as the local user."

USE_BZIP2=      YES
NO_LATEST_LINK=	YES
WRKSRC=         ${WRKDIR}/lynx2-8-3
GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib --libdir="${L_LIB}" \
		--enable-nsl-fork --enable-persistent-cookies
MAKE_FLAGS=     helpdir=${L_HELP} docdir=${L_DOC} -f
MAKEFILE=       makefile
INSTALL_TARGET= install-full
MAN1=		lynx.1

L_LIB=          ${PREFIX}/etc
L_DOC=          ${PREFIX}/share/doc/lynx
L_HELP=         ${PREFIX}/share/lynx_help

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${L_DOC}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${L_HELP}
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${L_LIB}/lynx.cfg

.include <bsd.port.mk>
