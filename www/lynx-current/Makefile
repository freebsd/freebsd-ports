# New ports collection makefile for:    lynx
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	lynx
PORTVERSION=	2.8.8d12
PORTREVISION=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://lynx.isc.org/current/
DISTNAME=	${PORTNAME}2.8.8dev.12

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A non-graphical, text-based World-Wide Web client

LIB_DEPENDS=	idn:${PORTSDIR}/dns/libidn
RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

CONFLICTS_INSTALL=	lynx-2.8.[0-7].* ja-lynx-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}2-8-8
USE_BZIP2=	yes
USE_ICONV=	yes
USE_OPENSSL=	yes
NO_LATEST_LINK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-zlib --libdir="${L_LIB}" \
		--enable-nsl-fork --with-bzlib \
		--enable-nested-tables --enable-default-colors \
		--enable-addrlist-page \
		--enable-gzip-help \
		--enable-idna \
		--enable-ipv6 \
		--with-mime-libdir=${PREFIX}/etc \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-screen=ncursesw \
		--with-ssl=${OPENSSLBASE}

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

MAKE_FLAGS=	helpdir=${L_HELP} docdir=${L_DOC} -f
MAKEFILE=	makefile
INSTALL_TARGET=	install-full
MAN1=		lynx.1

L_LIB=		${PREFIX}/etc
L_DOC=		${PREFIX}/share/doc/lynx
L_HELP=		${PREFIX}/share/lynx_help

.if ${PORT_OPTIONS:MNLS}
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

.include <bsd.port.mk>
