# New ports collection makefile for:    lynx
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

# NOTE: This port is tracking lynx-current until 2.8.3 is released.  Anything
#       before 2.8.3pre.2 has unacceptable security holes.

PORTNAME=	lynx
PORTVERSION=    2.8.3pre.5
CATEGORIES=	www
MASTER_SITES=   http://lynx.isc.org/current/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	jseger@FreeBSD.org

USE_BZIP2=      YES
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
