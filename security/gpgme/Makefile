# Created by: teramoto@comm.eng.osaka-u.ac.jp
# $FreeBSD$

PORTNAME=	gpgme
PORTVERSION=	1.5.0
CATEGORIES=	security
MASTER_SITES=	GNUPG/gpgme

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library to make access to GnuPG easier

LICENSE=	LGPL21

LIB_DEPENDS=	libassuan.so:${PORTSDIR}/security/libassuan \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error

GNU_CONFIGURE=	yes
USES=		gmake libtool:keepla tar:bzip2
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--includedir=${PREFIX}/include/gpgme

INFO=		gpgme
PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README THANKS TODO

OPTIONS_DEFINE=		DOCS UISERVER
OPTIONS_SINGLE=		GNUPG
OPTIONS_SINGLE_GNUPG=	GNUPG1 GNUPG2
OPTIONS_DEFAULT=	GNUPG2 UISERVER

GNUPG1_DESC=		Build gpgme library for GnuPG 1.x
GNUPG1_BUILD_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1
GNUPG1_RUN_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1

GNUPG2_DESC=		Build gpgme library for GnuPG 2.x
GNUPG2_BUILD_DEPENDS=	gpg2:${PORTSDIR}/security/gnupg
GNUPG2_RUN_DEPENDS=	gpg2:${PORTSDIR}/security/gnupg

UISERVER_DESC=			GnuPG UI server support
UISERVER_CONFIGURE_ENABLE=	fd-passing

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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgpgme*.so.*

.include <bsd.port.mk>
