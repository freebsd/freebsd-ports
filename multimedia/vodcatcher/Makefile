# Created by: ijliao
# $FreeBSD$

PORTNAME=	vodcatcher
PORTVERSION=	1.3.3
CATEGORIES=	multimedia ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Video podcast client for the command line

USE_RUBY=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

PLIST_FILES=	bin/vodcatcher

NO_STAGE=	yes
do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
