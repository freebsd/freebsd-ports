# New ports collection makefile for:    lynx
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	lynx
PORTVERSION=    2.8.5d17
PORTREVISION=	1
CATEGORIES=     www ipv6
MASTER_SITES=	http://lynx.isc.org/current/
DISTNAME=       ${PORTNAME}2.8.5dev.17

MAINTAINER=	ache@FreeBSD.org
COMMENT=	A non-graphical, text-based World-Wide Web client

WRKSRC=		${WRKDIR}/${PORTNAME}2-8-5
USE_BZIP2=	yes
USE_GETTEXT=	yes
NO_LATEST_LINK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-screen=ncurses --with-zlib --libdir="${L_LIB}" \
		--enable-nsl-fork --enable-nls --with-bzlib \
		--enable-nested-tables \
		--enable-scrollbar --enable-addrlist-page

.ifndef NO_OPENSSL
USE_OPENSSL=    yes
.endif

.include <bsd.port.pre.mk>

.ifdef USE_OPENSSL
CONFIGURE_ARGS+= --with-ssl=${OPENSSLBASE}
.endif

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+= --enable-ipv6
.else
CONFIGURE_ARGS+= --disable-ipv6
.endif
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CC="${CC} -I${LOCALBASE}/include" LDFLAGS="${LDFLAGS}" \
		LIBS=-lncurses
MAKE_FLAGS=	helpdir=${L_HELP} docdir=${L_DOC} -f
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

.include <bsd.port.post.mk>
