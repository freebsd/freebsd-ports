# Created by: ijliao
# $FreeBSD$

PORTNAME=	align
PORTVERSION=	1.7.3
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.indiana.edu/~kinzler/align/ \
		http://bitrote.org/distfiles/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Text column alignment filter

LICENSE=	GPLv2+

NO_BUILD=	yes

USES=		perl5 shebangfix tar:tgz
SHEBANG_FILES=	align width
USE_PERL5=	run

PLIST_FILES=	bin/align bin/width

do-install:
.for i in align width
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${i} ${STAGEDIR}${PREFIX}/bin)
.endfor

.include <bsd.port.mk>
