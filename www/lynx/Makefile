# New ports collection makefile for:	lynx
# Date created:				15 Dec 1994
# Whom:					Andrey Chernov <ache@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lynx
PORTVERSION=	2.8.6.5
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://lynx.isc.org/current/ \
		ftp://lynx.isc.org/lynx${PORTVERSION}/patches/:patches
DISTNAME=	${PORTNAME}${PORTVERSION:R}rel.${PORTVERSION:E}

MAINTAINER=	jharris@widomaker.com
COMMENT=	A non-graphical, text-based World-Wide Web client

CONFLICTS=	lynx-2.8.[7-9]*

USE_BZIP2=	yes
USE_OPENSSL=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}2-8-6
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-zlib --libdir="${L_LIB}" \
		--enable-nsl-fork --enable-persistent-cookies \
		--enable-nested-tables --enable-gzip-help \

MAKE_JOBS_UNSAFE=	yes

OPTIONS=	SSL		"SSL support" on \
		DEFAULT_COLORS	"Colors support" off \
		IPV6		"IPv6 support" off \
		NLS 		"Native language support" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602107 || (${OSVERSION} >= 700000 && ${OSVERSION} < 700033)
CONFIGURE_ARGS+=	--with-screen=ncurses
.else
CONFIGURE_ARGS+=	--with-screen=ncursesw
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS='@comment '
.else
USE_GETTEXT=	yes
USE_ICONV=	yes
CONFIGURE_ARGS+=--enable-nls --with-libiconv-prefix="${LOCALBASE}"
PLIST_SUB+=	NLS=''
.endif

.if defined(WITH_IPV6) && !defined(NO_INET6)
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if defined(WITH_SSL)
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.endif

.if defined(WITH_DEFAULT_COLORS) || defined(ENABLE_DEFAULT_COLORS)
CONFIGURE_ARGS+=--enable-default-colors
.endif

MAKE_ARGS=	helpdir=${L_HELP} docdir=${DOCSDIR}
MAKEFILE=	makefile
INSTALL_TARGET=	install-full
MAN1=		lynx.1

L_LIB=		${PREFIX}/etc
L_HELP=		${PREFIX}/share/lynx_help

SUB_FILES=	pkg-message

post-patch:
	@${RM} -f ${WRKSRC}/CHANGES.orig

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${L_HELP}
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${L_LIB}/lynx.cfg

.include <bsd.port.post.mk>
