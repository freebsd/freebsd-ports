# Ports collection makefile for:	cd9660_unicode
# Date created:				13 February 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cd9660_unicode
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sobomax

MAINTAINER=	sobomax@FreeBSD.org

NO_PACKAGE=	Should be in sync with the kernel to work correctly

SRCPREFIX?=	/usr/src
PKGMESSAGE=	${WRKDIR}/.MESSAGE
ENCODINGS=	cd ${WRKSRC}/templates && ${ECHO_CMD} [^C]* | \
			${SED} 's|\.txt|,|g'
FMT=		/usr/bin/fmt
FLAG!=		/usr/bin/grep -e cd9660_wchar2char \
			${SRCPREFIX}/sys/isofs/cd9660/cd9660_util.c 2>/dev/null || \
			/usr/bin/true

.if (${FLAG} == "")
BROKEN=		"your FreeBSD version is not supported. Please update to the latest version and try again"
.endif

pre-fetch:
	@if [ ! -d /sys -o ! -d ${SRCPREFIX}/sys ]; then \
		${ECHO} "****************************************" ; \
		${ECHO} " You need to extract kernel source tree" ; \
		${ECHO} " before you build this package..." ; \
		${ECHO} "****************************************" ; \
		${FALSE} ; \
	fi

pre-install:
	@ENCODINGS=`${ENCODINGS}` && \
		ENCODINGS=`${ECHO_CMD} $${ENCODINGS} | ${SED} 's|,$$||'` && \
		${SED} "s|%%PREFIX%%|${PREFIX}|g; s|%%ENCODINGS%%|$${ENCODINGS}|" \
			${PKGDIR}/pkg-message | ${FMT} > ${PKGMESSAGE}
	${MKDIR} ${PREFIX}/lib/cd9660_unicode

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
