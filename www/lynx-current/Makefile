# New ports collection makefile for:    lynx
# http://lynx.isc.org/current/
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	lynx
PORTVERSION=    2.8.3pre.5
CATEGORIES=	www
MASTER_SITES=   http://lynx.isc.org/current/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ache@FreeBSD.org

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
