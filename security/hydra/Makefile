# Created by: Laurent LEVIER <llevier@argosnet.com>
# $FreeBSD$

PORTNAME=	hydra
PORTVERSION=	8.1
CATEGORIES=	security
MASTER_SITES=	https://www.thc.org/releases/ \
		PACKETSTORM/groups/thc/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Brute force attack utility working on multiple network services

LICENSE=	AGPLv3

LIB_DEPENDS=	libidn.so:dns/libidn \
		libpcre.so:devel/pcre \
		libsasl2.so:security/cyrus-sasl2

CONFLICTS_INSTALL=	hydra-web-[0-9]*

PLIST_FILES=	bin/hydra bin/pw-inspector bin/dpl4hydra.sh bin/hydra-wizard.sh \
		man/man1/hydra.1.gz man/man1/pw-inspector.1.gz
GNU_CONFIGURE=	yes
USES=		gmake
USE_OPENSSL=	yes
WANT_GNOME=	yes

OPTIONS_DEFINE=	FIREBIRD SSH SVN X11
OPTIONS_DEFAULT=SSH
OPTIONS_EXCLUDE=NLS DOCS
FIREBIRD_USES=	firebird
SVN_LIB_DEPENDS=	libsvn_client-1.so:devel/subversion

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSH}
CFLAGS+=	-I${LOCALBASE}/include
LIB_DEPENDS+=	libssh.so.4:security/libssh
.endif

.if ${PORT_OPTIONS:MX11}
USES+=		pkgconfig
USE_GNOME=	gtk20
PLIST_FILES+=	bin/xhydra man/man1/xhydra.1.gz
.else
CONFIGURE_ARGS+=	--disable-xhydra
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|CC=gcc||; s|-O3|${CFLAGS}|;' \
		${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.unix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hydra ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pw-inspector ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/dpl4hydra.sh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/hydra-wizard.sh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hydra.1 ${STAGEDIR}${MANPREFIX}/man/man1/hydra.1
	${INSTALL_MAN} ${WRKSRC}/pw-inspector.1 ${STAGEDIR}${MANPREFIX}/man/man1/pw-inspector.1
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/hydra-gtk/src/xhydra ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xhydra.1 ${STAGEDIR}${MANPREFIX}/man/man1/xhydra.1
.endif

.include <bsd.port.mk>
