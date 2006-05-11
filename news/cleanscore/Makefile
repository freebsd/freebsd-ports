# New ports collection makefile for:   cleanscore
# Date created:        10 April 2002
# Whom:                Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	cleanscore
PORTVERSION=	0.9.8.1
CATEGORIES=	news
MASTER_SITES=	http://slrn.sourceforge.net/cleanscore/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A perl script to clean up your slrn score file

USE_PERL5_RUN=	yes
NO_BUILD=	yes

PORTDOCS=	README
PLIST_FILES=	bin/cleanscore

post-patch:
	@${REINPLACE_CMD} 's|^use warnings|#use warnings|g ; \
		s|^our |my |g' ${WRKSRC}/cleanscore

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cleanscore ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
