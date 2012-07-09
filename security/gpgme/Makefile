# New ports collection makefile for:	gpgme
# Date created:		15 June 2001
# Whom:			teramoto@comm.eng.osaka-u.ac.jp
#
# $FreeBSD$
#

PORTNAME=	gpgme
PORTVERSION=	1.3.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	gpgme
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	A library to make access to GnuPG easier

LICENSE=	LGPL21

LIB_DEPENDS=	assuan.0:${PORTSDIR}/security/libassuan \
		gpg-error.0:${PORTSDIR}/security/libgpg-error

OPTIONS_DEFINE=		DOCS UISERVER
OPTIONS_SINGLE=		GNUPG
OPTIONS_SINGLE_GNUPG=	GNUPG1 GNUPG2
OPTIONS_DEFAULT=	GNUPG2

GNUPG1_DESC=		Build gpgme library for GnuPG 1.x
GNUPG2_DESC=		Build gpgme library for GnuPG 2.x
UISERVER_DESC=		GnuPG UI server support

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--includedir=${PREFIX}/include/gpgme \
		--with-g13=no

INFO=		gpgme
PORTDOCS=	AUTHORS ChangeLog COPYING COPYING.LESSER INSTALL \
		NEWS README THANKS TODO

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUPG1}
BUILD_DEPENDS+=	gpgv:${PORTSDIR}/security/gnupg1
RUN_DEPENDS+=	gpgv:${PORTSDIR}/security/gnupg1
CONFIGURE_ARGS+=--with-gpg=${LOCALBASE}/bin/gpg \
		--with-gpgsm=no \
		--with-gpgconf=no
.endif

.if ${PORT_OPTIONS:MGNUPG2}
BUILD_DEPENDS+=	gpg2:${PORTSDIR}/security/gnupg
RUN_DEPENDS+=	gpg2:${PORTSDIR}/security/gnupg
CONFIGURE_ARGS+=--with-gpg=${LOCALBASE}/bin/gpg2 \
		--with-gpgconf=${LOCALBASE}/bin/gpgconf
.if exists(${LOCALBASE}/bin/gpgsm)
CONFIGURE_ARGS+=--with-gpgsm=${LOCALBASE}/bin/gpgsm
.else
CONFIGURE_ARGS+=--with-gpgsm=no
.endif
.endif

.if ${PORT_OPTIONS:MUISERVER}
CONFIGURE_ARGS+=--enable-fd-passing
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
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
