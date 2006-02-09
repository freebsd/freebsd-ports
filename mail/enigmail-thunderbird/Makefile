# New ports collection makefile for:	enigmail
# Date created:			20 January 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	enigmail
PORTVERSION=	0.94.0
CATEGORIES=	mail security
MASTER_SITES=	http://www.mozilla-enigmail.org/downloads/src/
PKGNAMEPREFIX?=	thunderbird-

MAINTAINER=	ale@FreeBSD.org
COMMENT?=	A GnuPG extension for the Thunderbird mail client

EXTRACT_DEPENDS=${GECKO_WRKSRC}/Makefile:${PORTSDIR}/${GECKO_PORTDIR}:configure \
		zip:${PORTSDIR}/archivers/zip \
		gmake:${PORTSDIR}/devel/gmake \
		intltool-extract:${PORTSDIR}/textproc/intltool
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	nspr4:${PORTSDIR}/devel/nspr
RUN_DEPENDS=	${GECKO}:${PORTSDIR}/${GECKO_PORTDIR} \
		gpg:${PORTSDIR}/security/gnupg

GECKO=		${PKGNAMEPREFIX:S/-//}
.if ${GECKO} == "thunderbird"
GECKO_PORTDIR=	mail/${GECKO}
.else
GECKO_PORTDIR=	www/${GECKO}
.endif
GECKO_WRKSRC=	${WRKDIR}/../../../${GECKO_PORTDIR}/work/mozilla
WRKSRC=		${WRKDIR}/mozilla

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gtk20 libidl

XPI_FILE=	${DISTNAME}-${GECKO}-freebsd-${ARCH}.xpi
PLIST_FILES=	%%DATADIR%%/${XPI_FILE}
PLIST_DIRS=	%%DATADIR%%

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CP} -R ${GECKO_WRKSRC} ${WRKSRC}
	@for f in ${EXTRACT_ONLY}; do \
		cd ${WRKSRC}/mailnews/extensions && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$f ${EXTRACT_AFTER_ARGS}; \
	done

pre-patch:
	@${REINPLACE_CMD} -e "s|${GECKO_PORTDIR}|mail/enigmail-${GECKO}|g" \
		`${FIND} ${WRKSRC} -name autoconf.mk`

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} export)
	@(cd ${WRKSRC}/modules/libreg; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
	@(cd ${WRKSRC}/xpcom/string; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
	@(cd ${WRKSRC}/xpcom; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
	@(cd ${WRKSRC}/xpcom/obsolete; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
	@(cd ${WRKSRC}/mailnews/extensions/enigmail; ./makemake -r; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS});
	@(cd ${WRKSRC}/mailnews/extensions/enigmail; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} xpi);

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dist/bin/${DISTNAME}-freebsd-${ARCH}.xpi ${DATADIR}/${XPI_FILE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
