# Ports collection makefile for:	logcheck
# Date created:		9 December 1999
# Whom:			Dan Langille <dan@freebsddiary.org>
#
# $FreeBSD$
#

PORTNAME=	logcheck
PORTVERSION=	1.1.1
CATEGORIES=	security
MASTER_SITES=	ftp://sensimilia.eu.org/pub/software/sys/ \
		http://www.ukc.mirror.ac.uk/sites/ftp.freebsd.org/pub/FreeBSD/ports/distfiles/ \
		http://www.psionic.com/downloads/ \
		http://people.FreeBSD.org/~foxfair/distfiles/
DISTNAME=	logsentry-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Auditing tool for system logs on Unix boxes

BROKEN=		"Changes permissions on /tmp to mode 0700"

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
