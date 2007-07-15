# New ports collection makefile for:	gprename
# Date created:				2004-03-15
# Whom:					trevor
#
# $Carpetsmoker: ports/x11-fm/gprename/Makefile,v 1.5 2007/07/12 02:30:53 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	gprename
PORTVERSION=	2.3
PORTEPOCH=	1
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	Perl script for renaming multiple files

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes
PORTDOCS=	README COPYING
MAN1=		gprename.1
MANCOMPRESSED=	no

post-patch:
	@${REINPLACE_CMD} 's|/usr/|${PREFIX}/|' \
		${WRKSRC}/bin/gprename
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|; \
		s|$$(CURDIR)|$$(.CURDIR)|; \
		s|share/man|man|;' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/COPYING ${DOCSDIR}
.endif

.include <bsd.port.mk>
