# Created by: Ryan Steinmetz <rpsfa@rit.edu>
# $FreeBSD$

PORTNAME=	truecrypt
PORTVERSION=	7.1a
CATEGORIES=	security
MASTER_SITES=	SF/wxwindows/${WX_VER}/:wxwidgets \
		ftp://ftp.rsasecurity.com/pub/pkcs/pkcs-11/v2-20/:rsa \
		http://mirrors.rit.edu/zi/pkcs-11/v2-20/:rsa
DISTFILES=	${TC_SRCFILE}:tc \
		wxWidgets-${WX_VER}.tar.gz:wxwidgets \
		pkcs11.h:rsa \
		pkcs11f.h:rsa \
		pkcs11t.h:rsa
EXTRACT_ONLY=	${TC_SRCFILE} wxWidgets-${WX_VER}.tar.gz

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Free open-source disk encryption software

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
RUN_DEPENDS=	sudo:${PORTSDIR}/security/sudo

WRKSRC=		${WRKDIR}/truecrypt-${PORTVERSION}-source

USES=		fuse iconv
USE_GMAKE=	yes
RESTRICTED=	Downloading requires acceptance of license agreement
NO_CDROM=	Distribution requires acceptance of license agreement
NO_PACKAGE=	Distribution requires acceptance of license agreement

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
PLIST_DIRS=	%%DOCSDIR%%
.endif

.if ${PORT_OPTIONS:MX11}
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
	cd ${WRKSRC} && ${GMAKE} ${NOGUI} PKCS11_INC=${WRKDIR}/rsa WX_ROOT=${WRKDIR}/wxWidgets-${WX_VER} wxbuild
	cd ${WRKSRC} && ${GMAKE} ${NOGUI} WXSTATIC=1 PKCS11_INC=${WRKDIR}/rsa

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/Main/truecrypt ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/License.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Release/Setup\ Files/TrueCrypt\ User\ Guide.pdf ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
