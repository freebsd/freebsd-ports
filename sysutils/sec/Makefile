# ex:ts=8
# New ports collection Makefile for:	sec
# Date created:			25, February 2003
# Whom:				Nicolas Jombart <ecu@ipv42.net>
#
# $FreeBSD$
#

PORTNAME=	sec
PORTVERSION=	2.5.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	simple-evcorr

MAINTAINER=	ecu@ipv42.net
COMMENT=	Simple event (logs) correlator

USE_PERL5_RUN=	YES
NO_BUILD=	YES

USE_RC_SUBR=	sec
SUB_LIST=	PERL=${PERL}

MAN8=		sec.8
PORTDOCS=	ChangeLog README
PLIST_FILES=	bin/sec
DATADIR=	share/sec
PORTCONTRIB=	convert.pl itostream.c swatch2sec.pl
PLIST_FILES+=	${PORTCONTRIB:S|^|%%DATADIR%%/|}
PLIST_DIRS+=	${DATADIR}

post-patch:
	@${REINPLACE_CMD} -e \
	's|${PORTNAME}.pl|${PORTNAME}|g' ${WRKSRC}/${PORTNAME}.pl.man

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sec.pl ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/sec.pl.man ${PREFIX}/man/man8/sec.8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${MKDIR} ${PREFIX}/${DATADIR}
	cd ${WRKSRC}/contrib && ${INSTALL_DATA} ${PORTCONTRIB} ${PREFIX}/${DATADIR}

.include <bsd.port.mk>
