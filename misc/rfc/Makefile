# New ports collection makefile for:	rfc
# Date created:				05 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	rfc
PORTVERSION=	3.2
CATEGORIES=	misc
MASTER_SITES=	http://www.dewn.com/rfc/
EXTRACT_SUFX=

MAINTAINER=	jedgar@FreeBSD.org

RUN_DEPENDS=	w3m:${PORTSDIR}/www/w3m

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKDIR}/${DISTNAME}

do-configure:
	@${PERL} -pi.orig -e 's|/usr/local/etc/rfc|${PREFIX}/etc/rfc| ; \
		s|/usr/local/etc/nmap|${PREFIX}/share/misc/nmap| ; \
		s|lynx|w3m|' ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME} ${PREFIX}/bin/${DISTNAME:S/-${PORTVERSION}//}

.include <bsd.port.mk>
