# New ports collection makefile for:	rfc
# Version required:			2.0
# Date created:				05 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	rfc
PKGNAME=	rfc-2.0
CATEGORIES=	misc
MASTER_SITES=	http://www.dewn.com/rfc/
EXTRACT_SUFX=

MAINTAINER=	jedgar@fxp.org

RUN_DEPENDS=	lynx:${PORTSDIR}/www/lynx

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKDIR}/${DISTNAME}

do-configure:
	@${MV} ${WRKDIR}/${DISTNAME} ${WRKDIR}/${DISTNAME}.orig
	@${SED} -e 's|/etc/rfc|${PREFIX}/etc/rfc|' -e 's|/etc/nmap|${PREFIX}/share/misc/nmap|' \
	   < ${WRKDIR}/${DISTNAME}.orig > ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rfc ${PREFIX}/bin/rfc

.include <bsd.port.mk>
