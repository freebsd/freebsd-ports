# New ports collection makefile for:	menushki
# Date created:				Fri Jul 13 22:59:59 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	menushki
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	misc x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@FreeBSD.org
COMMENT=	Menu converter between varieties of Window Managers

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

DOCS=	AUTHORS ChangeLog README TODO

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for files in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${files} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
