# Created by: Laurent LEVIER <llevier@argosnet.com>
# $FreeBSD$

PORTNAME=	hydra
PORTVERSION=	7.5
CATEGORIES=	security
MASTER_SITES=	http://freeworld.thc.org/releases/ \
		PACKETSTORM/groups/thc/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Brute force attack utility working on multiple network services

LICENSE=	AGPLv3

LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

CONFLICTS=	hydra-[0-9]*

NO_LATEST_LINK=	yes
PLIST_FILES=	bin/hydra bin/pw-inspector bin/dpl4hydra.sh
GNU_CONFIGURE=	yes
USES=		gmake
USE_OPENSSL=	yes
WANT_GNOME=	yes

MAN1=		hydra.1 pw-inspector.1

OPTIONS_DEFINE=	FIREBIRD SSH SVN X11
OPTIONS_EXCLUDE=NLS DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFIREBIRD}
LIB_DEPENDS+=	libfbclient.so:${PORTSDIR}/databases/firebird20-client
.endif

.if ${PORT_OPTIONS:MSSH}
CFLAGS+=	-I${LOCALBASE}/include
LIB_DEPENDS+=	libssh.so.4:${PORTSDIR}/security/libssh
.endif

.if ${PORT_OPTIONS:MSVN}
LIB_DEPENDS+=	libsvn_client-1.so:${PORTSDIR}/devel/subversion
.endif

.if ${PORT_OPTIONS:MX11}
USES+=		pkgconfig
USE_GNOME=	gtk20
PLIST_FILES+=	bin/xhydra
MAN1+=		xhydra.1
.else
CONFIGURE_ARGS+=	--disable-xhydra
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|CC = gcc||; \
		s|-O2|${CFLAGS}|; s|md4\..||g' \
		${WRKSRC}/Makefile.am

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hydra ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pw-inspector ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/dpl4hydra.sh ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hydra.1 ${MANPREFIX}/man/man1/hydra.1
	${INSTALL_MAN} ${WRKSRC}/pw-inspector.1 ${MANPREFIX}/man/man1/pw-inspector.1
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/hydra-gtk/src/xhydra ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xhydra.1 ${MANPREFIX}/man/man1/xhydra.1
.endif

.include <bsd.port.mk>
