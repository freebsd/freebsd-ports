# Ports collection makefile for:	aureal-kmod
# Date created:				15 January 2001
# Whom:					Maxim Sobolev <soobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aureal-kmod
PORTVERSION=	1.5
CATEGORIES=	misc
MASTER_SITES=	http://www.cis.ohio-state.edu/~matey/au88x0/
DISTNAME=	au88x0-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

NO_PACKAGE=	package doesn't make any sense, because kld's should be in sync with running kernel to work correctly

WRKSRC=		${WRKDIR}

PKGMESSAGE=	${WRKSRC}/.MESSAGE

MAKE_ENV=	WRKSRC="${WRKSRC}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
BROKEN=		"FreeBSD 3.* isn't supported"
.elif ${OSVERSION} < 500000
PORTVERSION=	1.3
.endif

pre-build:
	@if [ ! -d /sys -o ! -d /usr/src/sys ]; then \
		${ECHO} "****************************************" ; \
		${ECHO} " You need to extract kernel source tree" ; \
		${ECHO} " before you build this package..." ; \
		${ECHO} "****************************************" ; \
		${FALSE} ; \
	fi

pre-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	${MKDIR} ${PREFIX}/lib/au88x0

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
