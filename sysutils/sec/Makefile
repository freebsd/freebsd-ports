# New ports collection Makefile for: 	sec
# Date created:				25, February 2003
# Whom:					Nicolas Jombart <ecu@ipv42.net>
#
# $FreeBSD$
#

PORTNAME=	sec
PORTVERSION=	2.3.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	simple-evcorr

MAINTAINER=	ecu@ipv42.net
COMMENT=	Simple event (logs) correlator

USE_PERL5_RUN=	YES
NO_BUILD=	YES
USE_REINPLACE=	YES

MAN8=		sec.8
PORTDOCS=	ChangeLog README convert.pl itostream.c
PLIST_FILES=	bin/sec

post-patch:
	${REINPLACE_CMD} -e \
	's|${PORTNAME}.pl|${PORTNAME}|g' ${WRKSRC}/${PORTNAME}.pl.man

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/sec.pl ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/sec.pl.man ${PREFIX}/man/man8/sec.8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
