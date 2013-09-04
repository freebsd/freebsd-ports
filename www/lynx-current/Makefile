# Created by: ache
# $FreeBSD$

PORTNAME=	lynx
PORTVERSION=	2.8.8d15
CATEGORIES=	www ipv6
MASTER_SITES=	http://lynx.isc.org/current/
DISTNAME=	${PORTNAME}${PORTVERSION:C/d.*//}dev.${PORTVERSION:C/.*d//}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A non-graphical, text-based World-Wide Web client

LIB_DEPENDS=	idn:${PORTSDIR}/dns/libidn
RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

CONFLICTS_INSTALL=	lynx-2.8.[0-7].* ja-lynx-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/./-/g:C/d.*//}
USE_BZIP2=	yes
USES=		iconv
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
		${ICONV_CONFIGURE_ARG} \
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
USES+=		gettext
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
