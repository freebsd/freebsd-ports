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

USE_PERL5_RUN=	yes

PLIST_FILES=	bin/align bin/width

post-patch:
.for i in align width
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/${i}
.endfor

do-install:
.for i in align width
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${i} ${PREFIX}/bin)
.endfor

.include <bsd.port.mk>
