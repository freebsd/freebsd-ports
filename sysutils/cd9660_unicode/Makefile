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
ENCODINGS=	cd ${WRKSRC}/templates && ${ECHO} [^C]* | \
			${SED} 's|\.txt|,|g'
FMT=		/usr/bin/fmt

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"FreeBSD 3.*, 4.* are not supported"
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
		ENCODINGS=`${ECHO} $${ENCODINGS} | ${SED} 's|,$$||'` && \
		${SED} "s|%%PREFIX%%|${PREFIX}|g; s|%%ENCODINGS%%|$${ENCODINGS}|" \
			${PKGDIR}/pkg-message | ${FMT} > ${PKGMESSAGE}
	${MKDIR} ${PREFIX}/lib/cd9660_unicode

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
