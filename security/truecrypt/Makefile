# Created by: Ryan Steinmetz <rpsfa@rit.edu>
# $FreeBSD$

PORTNAME=	truecrypt
PORTVERSION=	7.1a
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	SF/wxwindows/${WX_VER}/:wxwidgets \
		ftp://ftp.rsasecurity.com/pub/pkcs/pkcs-11/v2-20/:rsa \
		http://mirrors.rit.edu/zi/pkcs-11/v2-20/:rsa
DISTFILES=	${TC_SRCFILE}:tc \
		wxWidgets-${WX_VER}.tar.bz2:wxwidgets \
		pkcs11.h:rsa \
		pkcs11f.h:rsa \
		pkcs11t.h:rsa
EXTRACT_ONLY=	${TC_SRCFILE} wxWidgets-${WX_VER}.tar.bz2

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Free open-source disk encryption software

BUILD_DEPENDS=	nasm:devel/nasm
RUN_DEPENDS=	sudo:security/sudo

WRKSRC=		${WRKDIR}/truecrypt-${PORTVERSION}-source

USES=		fuse iconv pkgconfig gmake
RESTRICTED=	May not be redistributed.  Must accept license to download.
NO_CDROM=	May not be redistributed.  Must accept license to download.
NO_PACKAGE=	May not be redistributed.  Must accept license to download.

TC_SRCFILE=	TrueCrypt_${PORTVERSION}_Source.tar.gz
WX_VER=		2.8.12

LICENSE_FILE=	${WRKSRC}/License.txt

PLIST_FILES=	bin/truecrypt

OPTIONS_DEFINE=	X11 DOCS
X11_DESC=	With GUI (depends on X)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_FILES+=	%%DOCSDIR%%/TrueCrypt\ User\ Guide.pdf
PLIST_FILES+=	%%DOCSDIR%%/License.txt
.endif

.if ${PORT_OPTIONS:MX11}
USES+=		gnome
USE_GNOME=	gtk20
NOGUI=
.else
NOGUI=		NOGUI=1
.endif

.if (!exists(${DISTDIR}/${TC_SRCFILE}))
DISTFILE_INSTRUCTIONS=\n\
Due to licensing restrictions, certain files must be fetched manually.\n\n\
Please visit http://www.truecrypt.org/downloads2 with a web browser and accept the\
License Agreement.\n\
Select the Mac OS X / Linux (.tar.gz) version\n\n\
Place the downloaded file into ${DISTDIR} and rename it to ${TC_SRCFILE}\n\n\
Then, please restart the build.\n\n
.endif

.if defined(DISTFILE_INSTRUCTIONS)
.if defined(PACKAGE_BUILDING)
IGNORE=		requires manual fetch
.else
pre-fetch:
	@${PRINTF} "${DISTFILE_INSTRUCTIONS}"
	@exit 1
.endif
.endif

do-build:
	@${MKDIR} ${WRKDIR}/rsa
	@${CP} ${DISTDIR}/pkcs11.h ${WRKDIR}/rsa
	@${CP} ${DISTDIR}/pkcs11t.h ${WRKDIR}/rsa
	@${CP} ${DISTDIR}/pkcs11f.h ${WRKDIR}/rsa
	@${ECHO_MSG} "===>  Building for wxWidgets dependency"
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${NOGUI} PKCS11_INC=${WRKDIR}/rsa WX_ROOT=${WRKDIR}/wxWidgets-${WX_VER} wxbuild)
	@${ECHO_MSG} "===>  Building for ${PKGNAME}"
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${NOGUI} WXSTATIC=1 PKCS11_INC=${WRKDIR}/rsa)

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/Main/truecrypt ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/License.txt ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Release/Setup\ Files/TrueCrypt\ User\ Guide.pdf ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
