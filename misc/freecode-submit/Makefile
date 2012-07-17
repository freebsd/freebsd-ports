# New ports collection makefile for:	freecode-submit (before freshmeat-submit)
# Date created:		2 Jan 2005
# Whom:			x
#
# $FreeBSD$
#

PORTNAME=	freecode-submit
PORTVERSION=	2.4
CATEGORIES=	misc
MASTER_SITES=	http://www.catb.org/~esr/freecode-submit/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Submission of updates to Freecode via its JSON API

LICENSE=	BSD

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/freecode-submit
MAN1=		freecode-submit.1

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freecode-submit ${PREFIX}/bin
	${MKDIR} ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/freecode-submit.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
