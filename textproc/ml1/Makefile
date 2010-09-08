# Ports collection makefile for:	ml1
# Date created:				29 August 2010
# Whom:					Bob Eager <rde@ml1.org.uk>
#
# $FreeBSD$
#

PORTNAME=	ml1
PORTVERSION=	4.10
CATEGORIES=	textproc
MASTER_SITES=	http://www.ml1.org.uk/tgz/ \
		http://www.tavi.co.uk/tgz/

MAINTAINER=	bob@eager.cx
COMMENT=	The original general purpose macro processor

MAN1=		ml1.1
MANCOMPRESSED=	yes

PLIST_FILES=	bin/ml1

.include <bsd.port.pre.mk>

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/ml1 ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/ml1.1.gz ${PREFIX}/man/man1

post-install:
		${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
