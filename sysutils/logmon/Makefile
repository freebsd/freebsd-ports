# New ports collection makefile for:	logmon
# Date created:				12 September 2001
# Whom:					Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	logmon
PORTVERSION=	0.4.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.edespot.com/code/LogMon/
DISTNAME=	LogMon-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An ncurses-based split window log monitoring program

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/logmon %%EXAMPLESDIR%%/logmon.conf.example
PLIST_DIRS=	%%EXAMPLESDIR%%
USE_GMAKE=	yes

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/logmon.conf.example ${EXAMPLESDIR}

.include <bsd.port.mk>
