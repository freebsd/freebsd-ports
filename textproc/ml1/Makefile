# Created by: Bob Eager <rde@ml1.org.uk>
# $FreeBSD$

PORTNAME=	ml1
PORTVERSION=	4.11
CATEGORIES=	textproc
MASTER_SITES=	http://www.ml1.org.uk/tgz/ \
		http://www.ancientgeek.org.uk/tgz/

MAINTAINER=	bob@eager.cx
COMMENT=	Original general purpose macro processor

PLIST_FILES=	bin/ml1 man/man1/ml1.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ml1 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ml1.1.gz \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
