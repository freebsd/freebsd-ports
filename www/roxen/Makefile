# New ports collection makefile for:	Roxen Challenger
# Date created:		26 February 1999
# Whom:			Kai Voigt (k@123.org)
#
# $FreeBSD$
#

PORTNAME=	roxen
PORTVERSION=	1.3.111
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.roxen.com/roxen/source/
DISTNAME=	roxen_1.3.111-0.6-40bit

MAINTAINER=	k@123.org

WRKSRC=		${WRKDIR}/roxen_1.3.111
GNU_CONFIGURE=	yes
PKGMESSAGE=	${WRKSRC}/MESSAGE

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/roxen.sh

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

.include <bsd.port.mk>
