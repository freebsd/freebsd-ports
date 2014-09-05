# Created by: ijliao
# $FreeBSD$

PORTNAME=	podcatcher
PORTVERSION=	3.1.6
CATEGORIES=	multimedia ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Podcast client for the command line

USE_RUBY=	yes
USES=		shebangfix
SHEBANG_FILES=	bin/${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

DEPRECATED=	RubyForge shutdown May 15 2014
EXPIRATION_DATE=	2014-09-20

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/demo; ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
