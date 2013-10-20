# Created by: teramoto@comm.eng.osaka-u.ac.jp
# $FreeBSD$

PORTNAME=	gpgme
PORTVERSION=	1.4.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	gpgme
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library to make access to GnuPG easier

LICENSE=	LGPL21

LIB_DEPENDS=	libassuan.so:${PORTSDIR}/security/libassuan \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	ltverhack
USES=		gmake
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--includedir=${PREFIX}/include/gpgme \
		--with-g13=no

INFO=		gpgme
PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README THANKS TODO

OPTIONS_DEFINE=		DOCS UISERVER
OPTIONS_SINGLE=		GNUPG
OPTIONS_SINGLE_GNUPG=	GNUPG1 GNUPG2
OPTIONS_DEFAULT=	GNUPG2 UISERVER

GNUPG1_DESC=		Build gpgme library for GnuPG 1.x
GNUPG1_BUILD_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1
GNUPG1_RUN_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1
GNUPG1_CONFIGURE_ON=	--with-gpg=${LOCALBASE}/bin/gpg \
			--with-gpgconf=no \
			--with-gpgsm=no

GNUPG2_DESC=		Build gpgme library for GnuPG 2.x
GNUPG2_BUILD_DEPENDS=	gpg2:${PORTSDIR}/security/gnupg
GNUPG2_RUN_DEPENDS=	gpg2:${PORTSDIR}/security/gnupg
GNUPG2_CONFIGURE_ON=	--with-gpg=${LOCALBASE}/bin/gpg2 \
			--with-gpgconf=${LOCALBASE}/bin/gpgconf

UISERVER_DESC=			GnuPG UI server support
UISERVER_CONFIGURE_ENABLE=	fd-passing

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUPG2}
.if exists(${LOCALBASE}/bin/gpgsm)
CONFIGURE_ARGS+=--with-gpgsm=${LOCALBASE}/bin/gpgsm
.else
CONFIGURE_ARGS+=--with-gpgsm=no
.endif
.endif

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
					${WRKSRC}/${CONFIGURE_SCRIPT} \
					${WRKSRC}/src/Makefile.in \
					${WRKSRC}/src/gpgme-config.in \
					${WRKSRC}/tests/gpg/Makefile.in
	@${REINPLACE_CMD} -e 's|^clfilesdir.*|clfilesdir=$$\(libdir\)/common-lisp/gpgme|g' \
					${WRKSRC}/lang/cl/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
