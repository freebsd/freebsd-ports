# Created by: ijliao
# $FreeBSD$

PORTNAME=	patchutils
PORTVERSION=	0.3.3
CATEGORIES=	misc
MASTER_SITES=	http://cyberelk.net/tim/data/patchutils/stable/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A small collection of programs that operate on patch files

USE_XZ=		yes
USES=		perl5
USE_PERL5=	run build patch
GNU_CONFIGURE=	yes

MAN1=	combinediff.1 dehtmldiff.1 editdiff.1 espdiff.1 filterdiff.1 \
	fixcvsdiff.1 flipdiff.1 grepdiff.1 interdiff.1 lsdiff.1 recountdiff.1 \
	rediff.1 splitdiff.1 unwrapdiff.1

post-patch:
	@${GREP} -lR "#!/bin/bash" ${WRKSRC} | ${XARGS} ${PERL} -pi.bak -e \
		"s,#!/bin/bash,#!/bin/sh,"

.include <bsd.port.mk>
