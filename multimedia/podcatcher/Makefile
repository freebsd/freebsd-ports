# ex:ts=8
# Ports collection makefile for:	podcatcher
# Date created:			Sep 5, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	podcatcher
PORTVERSION=	3.1.5
CATEGORIES=	multimedia ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Podcast client for the command line

USE_RUBY=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

PLIST_FILES=	bin/podcatcher \
		${EXAMPLESDIR_REL}/arguments.txt \
		${EXAMPLESDIR_REL}/options.yaml \
		${EXAMPLESDIR_REL}/subscriptions.pcast \
		${EXAMPLESDIR_REL}/subscriptions.opml

PLIST_DIRS=	${EXAMPLESDIR_REL}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin

post-install:
	@${MKDIR}	${EXAMPLESDIR} \
	&& \
	( cd ${WRKSRC}/demo \
		&& ${COPYTREE_SHARE} \* ${EXAMPLESDIR} \
	)

.include <bsd.port.mk>
