# Ports collection makefile for:	logcheck
# Date created:		9 December 1999
# Whom:			Dan Langille <dan@freebsddiary.org>
#
# $FreeBSD$
#

PORTNAME=	logcheck
PORTVERSION=	1.1.1
CATEGORIES=	security
MASTER_SITES=	http://www.psionic.com/tools/

MAINTAINER=	ports@freebsddiary.org

PKGMESSAGE=	${WRKDIR}/MESSAGE

pre-configure:                                        
	${PERL} -pi -e "s@/usr/local/etc/tmp@${PREFIX}/var/tmp@g" ${WRKSRC}/Makefile ${WRKSRC}/systems/freebsd/logcheck.sh
	${PERL} -pi -e "s@/bin/mkdir@${MKDIR}@g" ${WRKSRC}/Makefile

post-build:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
