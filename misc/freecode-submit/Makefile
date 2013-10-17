# $FreeBSD$

PORTNAME=	freecode-submit
PORTVERSION=	2.6
CATEGORIES=	misc
MASTER_SITES=	http://www.c-s.li/ports/ \
		http://www.catb.org/~esr/freecode-submit/
		

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Submission of updates to Freecode via its JSON API

LICENSE=	BSD

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/freecode-submit man/man1/freecode-submit.1.gz

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/freecode-submit ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/freecode-submit.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
