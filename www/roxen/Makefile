# New ports collection makefile for:	Roxen WebServer
# Date created:				07 April 2001
# Whom:					Kai Voigt (k@123.org)
#
# $FreeBSD$
#

PORTNAME=	roxen
PORTVERSION=	2.1.231
CATEGORIES=	www
MASTER_SITES=	http://download.roxen.com/2.1/lzw/dl.html/
FETCH_CMD=	/usr/bin/fetch
DISTNAME=	roxen-dist-2.1.231
WRKSRC=		${WRKDIR}/roxen-${PORTVERSION}-src
MAINTAINER=	k@123.org
COMMENT=	The Roxen WebServer 2.1
HAS_CONFIGURE=	yes
PKGMESSAGE=     ${WRKSRC}/MESSAGE
STARTUP_SCRIPT= ${PREFIX}/etc/rc.d/roxen.sh.sample

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" ${FILESDIR}/roxen.sh.in > \
	  ${WRKDIR}/roxen.sh
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" ${FILESDIR}/MESSAGE.in > \
	  ${PKGMESSAGE}

do-configure:
	@(cd ${WRKSRC}; \
	  ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

post-install:
	@if [ ! -f ${STARTUP_SCRIPT} ]; then \
	  ${ECHO} "Installing ${STARTUP_SCRIPT} startup file."; \
	  ${INSTALL_SCRIPT} ${WRKDIR}/roxen.sh ${STARTUP_SCRIPT}; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha"
.endif

.if defined(PARALLEL_PACKAGE_BUILD) && ${OSVERSION} >= 500000
IGNORE=	hang
.endif

.include <bsd.port.post.mk>
