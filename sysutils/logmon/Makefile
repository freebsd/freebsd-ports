# Created by: Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
# $FreeBSD$

PORTNAME=	logmon
PORTVERSION=	0.4.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.edespot.com/code/LogMon/
DISTNAME=	LogMon-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ncurses-based split window log monitoring program

LICENSE=	ART10

USES=		ncurses
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/logmon.conf.example ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
