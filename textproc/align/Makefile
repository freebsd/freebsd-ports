# Created by: ijliao
# $FreeBSD$

PORTNAME=	align
PORTVERSION=	1.7.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.indiana.edu/~kinzler/align/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text column alignment filter

LICENSE=	GPLv2 # (or later)

NO_BUILD=	yes

USES=		shebangfix perl5
USE_PERL5=	run

SHEBANG_FILES=	align width

PLIST_FILES=	bin/align bin/width

do-install:
.for i in align width
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${i} ${PREFIX}/bin)
.endfor

.include <bsd.port.mk>
