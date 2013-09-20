# Created by: Andrey Chernov <ache@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lynx
PORTVERSION=	2.8.7.2
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://lynx.isc.org/current/
DISTNAME=	${PORTNAME}${PORTVERSION:R}rel.${PORTVERSION:E}

MAINTAINER=	jharris@widomaker.com
COMMENT=	Non-graphical, text-based World-Wide Web client

CONFLICTS=	lynx-2.8.[8-9]*

USE_BZIP2=	yes
USE_OPENSSL=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}2-8-7
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-zlib --libdir="${L_LIB}" \
		--enable-nsl-fork --enable-persistent-cookies \
		--enable-nested-tables --enable-gzip-help \
		--with-screen=ncursesw

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DEFAULT_COLORS IPV6 NLS SSL
OPTIONS_DEFAULT=	SSL
DEFAULT_COLORS_DESC=	Colors support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MNLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS='@comment '
.else
USES+=		gettext iconv
CONFIGURE_ARGS+=--enable-nls ${ICONV_CONFIGURE_ARG}
PLIST_SUB+=	NLS=''
.endif

.if ${PORT_OPTIONS:MIPV6} && !defined(NO_INET6)
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.endif

.if ${PORT_OPTIONS:MDEFAULT_COLORS}
CONFIGURE_ARGS+=--enable-default-colors
.endif

.if empty(PORT_OPTIONS:MDOCS)
CONFIGURE_ARGS+=--disable-local-docs
INSTALL_TARGET=	install
DOCSDIR=
L_HELP=
.else
INSTALL_TARGET=	install-full
L_HELP=		${PREFIX}/share/lynx_help
MAKE_ARGS=	helpdir=${L_HELP} docdir=${DOCSDIR}
.endif

MAKEFILE=	makefile
MAN1=		lynx.1

L_LIB=		${PREFIX}/etc

SUB_FILES=	pkg-message

post-install:
.if empty(PORT_OPTIONS:MDOCS)
	[ -f ${L_LIB}/lynx.cfg ] || ${INSTALL} ${L_LIB}/lynx.cfg.sample ${L_LIB}/lynx.cfg
	[ -f ${L_LIB}/lynx.lss ] || ${INSTALL} ${L_LIB}/lynx.lss.sample ${L_LIB}/lynx.lss
.else
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${L_HELP}
.endif
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${L_LIB}/lynx.cfg

.include <bsd.port.mk>
