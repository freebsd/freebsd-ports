# New ports collection makefile for:	freshmeat-submit
# Date created:		2 Jan 2005
# Whom:			x
#
# $FreeBSD$
#

PORTNAME=	freshmeat-submit
PORTVERSION=	1.6
CATEGORIES=	misc
MASTER_SITES=	http://www.catb.org/~esr/freshmeat-submit/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Submission of updates to Freshmeat via its XML-RPC

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/freshmeat-submit
MAN1=		freshmeat-submit.1

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freshmeat-submit ${PREFIX}/bin
	${MKDIR} ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/freshmeat-submit.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
