# New ports collection Makefile for: 	sec
# Date created:				25, February 2003
# Whom:					Nicolas Jombart <ecu@ipv42.net>
#
# $FreeBSD$
#

PORTNAME=	sec
PORTVERSION=	2.1.9
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sourceforge/simple-evcorr

MAINTAINER=	ecu@ipv42.net
COMMENT=	Simple event (logs) correlator

USE_PERL5=	YES
NO_BUILD=	YES
USE_REINPLACE=	yes

MAN8=		sec.8
DOCS=		README convert.pl itostream.c

post-patch:
	${REINPLACE_CMD} -e \
	's|${PORTNAME}.pl|${PORTNAME}|g' \
		${WRKSRC}/${PORTNAME}.pl.man

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/sec.pl ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/sec.pl.man ${PREFIX}/man/man8/sec.8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
