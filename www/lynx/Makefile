# New ports collection makefile for:    lynx
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	lynx
PORTVERSION=	2.8.4.1
CATEGORIES=	www
MASTER_SITES=	http://lynx.isc.org/current/
DISTNAME=	${PORTNAME}2.8.4rel.1

MAINTAINER=	ports@FreeBSD.org

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}2-8-4
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-screen=ncurses --with-zlib --libdir="${L_LIB}" \
		--enable-nsl-fork --enable-persistent-cookies
MAKE_ARGS=	helpdir=${L_HELP} docdir=${L_DOC}
MAKEFILE=	makefile
INSTALL_TARGET=	install-full
MAN1=		lynx.1

L_LIB=		${PREFIX}/etc
L_DOC=		${PREFIX}/share/doc/lynx
L_HELP=		${PREFIX}/share/lynx_help

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${L_DOC}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${L_HELP}
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${L_LIB}/lynx.cfg

.include <bsd.port.mk>
