# New ports collection makefile for:	giFT library
# Date created:				Fri Nov 16 02:47:45 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	giFT
PORTVERSION=	0.9.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}

MAINTAINER=	lioux@FreeBSD.org

BROKEN=		'Does not currently work'

GNU_CONFIGURE=	yes

DOC_FILES=	AUTHORS COPYING ChangeLog \
		INSTALL NEWS README TODO

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
