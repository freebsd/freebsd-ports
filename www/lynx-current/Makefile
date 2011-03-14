# New ports collection makefile for:    lynx
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	lynx
PORTVERSION=	2.8.8d8
PORTREVISION=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://lynx.isc.org/current/
DISTNAME=	${PORTNAME}2.8.8dev.8

MAINTAINER=	ache@FreeBSD.org
COMMENT=	A non-graphical, text-based World-Wide Web client

LIB_DEPENDS=	idn.17:${PORTSDIR}/dns/libidn
RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

CONFLICTS=	lynx-2.8.[0-7].*

WRKSRC=		${WRKDIR}/${PORTNAME}2-8-8
USE_BZIP2=	yes
USE_ICONV=	yes
NO_LATEST_LINK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-zlib --libdir="${L_LIB}" \
		--enable-nsl-fork --with-bzlib \
		--enable-nested-tables --enable-default-colors \
		--enable-addrlist-page \
		--enable-gzip-help \
		--enable-idna \
		--enable-ipv6 \
		--with-mime-libdir=${PREFIX}/etc \
		--with-libiconv-prefix=${LOCALBASE}
MAKE_JOBS_UNSAFE=	yes

.ifndef NO_OPENSSL
USE_OPENSSL=	yes
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602107 || (${OSVERSION} >= 700000 && ${OSVERSION} < 700033)
CONFIGURE_ARGS+=	--with-screen=ncurses
.else
CONFIGURE_ARGS+=	--with-screen=ncursesw
.endif

.ifdef USE_OPENSSL
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.endif

MAKE_FLAGS=	helpdir=${L_HELP} docdir=${L_DOC} -f
MAKEFILE=	makefile
INSTALL_TARGET=	install-full
MAN1=		lynx.1

L_LIB=		${PREFIX}/etc
L_DOC=		${PREFIX}/share/doc/lynx
L_HELP=		${PREFIX}/share/lynx_help

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CONFIGURE_ARGS+=	--enable-nls
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${L_DOC}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${L_HELP}
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${L_LIB}/lynx.cfg* ${L_LIB}/lynx.lss*

.include <bsd.port.post.mk>
