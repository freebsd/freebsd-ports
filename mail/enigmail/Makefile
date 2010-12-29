# New ports collection makefile for:	enigmail
# Date created:			20 January 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	enigmail
PORTVERSION?=	1.0.1
PORTREVISION=	1
CATEGORIES=	mail security
MASTER_SITES=	http://www.mozilla-enigmail.org/download/source/
PKGNAMEPREFIX=	${GECKO}-

MAINTAINER=	ale@FreeBSD.org
COMMENT?=	A GnuPG extension for the Mozilla mail clients

EXTRACT_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/${GECKO_PORTDIR}:configure \
		${GECKO:C/[0-9]//}:${PORTSDIR}/${GECKO_PORTDIR} \
		gmake:${PORTSDIR}/devel/gmake \
		intltool-extract:${PORTSDIR}/textproc/intltool \
		${LOCALBASE}/libdata/pkgconfig/printproto.pc:${PORTSDIR}/x11/printproto
BUILD_DEPENDS=	${GECKO:C/[0-9]//}:${PORTSDIR}/${GECKO_PORTDIR}
RUN_DEPENDS=	${GECKO:C/[0-9]//}:${PORTSDIR}/${GECKO_PORTDIR} \
		gpg:${PORTSDIR}/security/gnupg

.if !defined(GECKO)
GECKO=		libxul
GECKO_PORTDIR=	www/${GECKO}
IGNORE=		is an abstract port: use one of the slave ports
.endif

.if defined(GECKO_EXTDIR)
GECKO_WRKSRC=	${WRKDIR}/../../../${GECKO_PORTDIR}/work/${GECKO_EXTDIR}
WRKSRC=		${WRKDIR}/${GECKO_EXTDIR}
MOZSRC=		${WRKSRC}/mozilla
.else
GECKO_WRKSRC=	${WRKDIR}/../../../${GECKO_PORTDIR}/work/mozilla
WRKSRC=		${WRKDIR}/mozilla
MOZSRC=		${WRKSRC}
.endif

USE_GMAKE=	yes

.include <bsd.port.pre.mk>

XPI_FILE=	${DISTNAME}-${GECKO}-freebsd${OSVERSION:C/([0-9]).+/\1/}-${ARCH}.xpi
PLIST_FILES=	%%DATADIR%%/${XPI_FILE}
PLIST_DIRS=	%%DATADIR%%

.if ${ARCH} == "sparc64"
.if ${GECKO} == "seamonkey" || ${GECKO} == "thunderbird"
BROKEN=		Does not install on sparc64
.endif
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CP} -Rp ${GECKO_WRKSRC} ${WRKDIR}
	@for f in ${EXTRACT_ONLY}; do \
		cd ${WRKSRC}/mailnews/extensions && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$f ${EXTRACT_AFTER_ARGS}; \
	done

pre-patch:
	@${REINPLACE_CMD} -e "s|${GECKO_PORTDIR}|mail/enigmail-${GECKO}|g" \
		`${FIND} ${WRKSRC} -name autoconf.mk`

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} export)
	@(cd ${MOZSRC}/modules/libreg; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
	@(cd ${MOZSRC}/xpcom/string; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
	@(cd ${MOZSRC}/xpcom; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
	@(cd ${MOZSRC}/xpcom/obsolete; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
	@(cd ${WRKSRC}/mailnews/extensions/enigmail; ./makemake -r; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS});
	@(cd ${WRKSRC}/mailnews/extensions/enigmail; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} xpi);

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${MOZSRC}/dist/bin/${DISTNAME:C/1.0.[0-9]/1.0/}-freebsd-${ARCH}.xpi ${DATADIR}/${XPI_FILE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
