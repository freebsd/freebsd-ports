# New ports collection makefile for:	rfc
# Date created:				05 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	rfc
PORTVERSION=	2.2
CATEGORIES=	misc
MASTER_SITES=	http://www.dewn.com/rfc/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=

MAINTAINER=	jedgar@FreeBSD.org

RUN_DEPENDS=	w3m:${PORTSDIR}/www/w3m

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKDIR}/${DISTNAME}

do-configure:
	@${PERL} -pi.orig -e 's|/etc/rfc|${PREFIX}/etc/rfc|' ${WRKDIR}/${DISTNAME}
	@${PERL} -pi.orig -e 's|/etc/nmap|${PREFIX}/share/misc/nmap|' ${WRKDIR}/${DISTNAME}
	@${PERL} -pi.orig -e 's|lynx|w3m|' ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rfc ${PREFIX}/bin/rfc

.include <bsd.port.mk>
