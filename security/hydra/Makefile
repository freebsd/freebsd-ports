PORTNAME=	hydra
DISTVERSIONPREFIX=v
DISTVERSION=	9.6
CATEGORIES=	security

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Brute force attack utility working on multiple network services
WWW=		https://github.com/vanhauser-thc/thc-hydra

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libidn.so:dns/libidn \
		libpcre.so:devel/pcre \
		libsasl2.so:security/cyrus-sasl2

USES=		gmake localbase ssl

USE_GITHUB=	yes
GH_ACCOUNT=	vanhauser-thc
GH_PROJECT=	thc-hydra

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ssl=${OPENSSLINC} \
		--with-ssl-lib=${OPENSSLLIB}
PLIST_FILES=	bin/hydra bin/pw-inspector bin/dpl4hydra.sh bin/hydra-wizard.sh \
		share/man/man1/hydra.1.gz share/man/man1/pw-inspector.1.gz

OPTIONS_DEFINE=	FIREBIRD SSH SUBVERSION X11
OPTIONS_DEFAULT=SSH
OPTIONS_EXCLUDE=NLS DOCS
FIREBIRD_USES=	firebird
.if ${WITH_SUBVERSION_VER:U} == LTS
SUBVERSION_LIB_DEPENDS=	libsvn_client-1.so:devel/subversion-lts
.else
SUBVERSION_LIB_DEPENDS=	libsvn_client-1.so:devel/subversion
.endif
SSH_LIB_DEPENDS=	libssh.so.4:security/libssh
X11_USES=		gettext gnome pkgconfig
X11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
X11_USE=		gnome=atk,cairo,gdkpixbuf,glib20,gtk20,pango
X11_PLIST_FILES=	bin/xhydra share/man/man1/xhydra.1.gz

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mlibressl*}
IGNORE=	detected LibreSSL (missing RSA_get0_key and others)
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
	${INSTALL_MAN} ${WRKSRC}/hydra.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/pw-inspector.1 ${STAGEDIR}${PREFIX}/share/man/man1
post-install-X11-on:
	${INSTALL_PROGRAM} ${WRKSRC}/hydra-gtk/src/xhydra ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xhydra.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.post.mk>
