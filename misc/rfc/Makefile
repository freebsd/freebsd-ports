# New ports collection makefile for:	rfc
# Date created:				05 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	rfc
PORTVERSION=	3.2.2
CATEGORIES=	misc
MASTER_SITES=	http://www.dewn.com/rfc/

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	Perl script to search for RFC's

RUN_DEPENDS=	w3m:${PORTSDIR}/www/w3m

NO_BUILD=	yes
USE_REINPLACE=	yes

MAN1=		rfc.1
PLIST_FILES=	bin/rfc

do-configure:
	@${REINPLACE_CMD} -e 's|/usr/local/etc/rfc|${PREFIX}/etc/rfc| ; \
		s|/usr/local/etc/nmap|${PREFIX}/share/misc/nmap|' \
		${WRKSRC}/${PORTNAME}-${PORTVERSION}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-${PORTVERSION} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
