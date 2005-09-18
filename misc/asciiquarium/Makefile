#
# New ports collection makefile for:    asciiquarium
# Date created:                         18 september 2005
# Whom:                                 Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	asciiquarium
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	http://www.robobunny.com/projects/asciiquarium/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	An aquarium/sea animation in ASCII art

BUILD_DEPENDS=	${SITE_PERL}/Term/Animation.pm:${PORTSDIR}/misc/p5-Term-Animation
RUN_DEPENDS=	${BUILD_DEPENDS}

PLIST_FILES=	bin/asciiquarium

USE_PERL5_RUN=	yes
NO_BUILD=	yes

PORTDOCS=	CHANGES README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/asciiquarium ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
