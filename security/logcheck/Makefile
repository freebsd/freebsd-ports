# Ports collection makefile for:	logcheck
# Date created:		9 December 1999
# Whom:			Dan Langille <dan@freebsddiary.org>
#
# $FreeBSD$
#

PORTNAME=	logcheck
PORTVERSION=	1.1.1
CATEGORIES=	security
MASTER_SITES=	http://www.psionic.com/downloads/
DISTNAME=	logsentry-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/MESSAGE

pre-configure:
	${REINPLACE_CMD} -e "s@/usr/local/etc/tmp@/tmp@g; \
		s@/usr/local@${PREFIX}@" ${WRKSRC}/Makefile \
		${WRKSRC}/systems/freebsd/logcheck.sh
	${REINPLACE_CMD} -e "s@/bin/mkdir@${MKDIR}@g" ${WRKSRC}/Makefile

post-build:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
