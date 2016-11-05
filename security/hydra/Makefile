# Created by: Laurent LEVIER <llevier@argosnet.com>
# $FreeBSD$

PORTNAME=	hydra
PORTVERSION=	8.3
CATEGORIES=	security
MASTER_SITES=	https://www.thc.org/releases/ \
		PACKETSTORM/groups/thc/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Brute force attack utility working on multiple network services

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libidn.so:dns/libidn \
		libpcre.so:devel/pcre \
		libsasl2.so:security/cyrus-sasl2

PLIST_FILES=	bin/hydra bin/pw-inspector bin/dpl4hydra.sh bin/hydra-wizard.sh \
		man/man1/hydra.1.gz man/man1/pw-inspector.1.gz
GNU_CONFIGURE=	yes
USES=		gmake localbase ssl
CONFIGURE_ARGS=	--with-ssl=${OPENSSLINC} \
		--with-ssl-lib=${OPENSSLLIB}

OPTIONS_DEFINE=	FIREBIRD SSH SVN X11
OPTIONS_DEFAULT=SSH
OPTIONS_EXCLUDE=NLS DOCS
FIREBIRD_USES=	firebird
SVN_LIB_DEPENDS=	libsvn_client-1.so:devel/subversion
SSH_LIB_DEPENDS=	libssh.so.4:security/libssh
X11_USES=		gettext pkgconfig
X11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
X11_USE=		gnome=atk,cairo,gdkpixbuf2,glib20,gtk20,pango
X11_PLIST_FILES=	bin/xhydra man/man1/xhydra.1.gz

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mlibressl*}
IGNORE=	Detected LibreSSL (missing RSA_get0_key and others)
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
	${INSTALL_MAN} ${WRKSRC}/hydra.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pw-inspector.1 ${STAGEDIR}${MANPREFIX}/man/man1
post-install-X11-on:
	${INSTALL_PROGRAM} ${WRKSRC}/hydra-gtk/src/xhydra ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xhydra.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
