# Created by: ijliao

PORTNAME=	align
PORTVERSION=	1.7.5
CATEGORIES=	textproc
MASTER_SITES=	https://kinzler.com/me/align/ \
		http://bitrote.org/distfiles/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Text column alignment filter

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

NO_BUILD=	yes

USES=		perl5 shebangfix tar:tgz
SHEBANG_FILES=	align width
USE_PERL5=	run

CONFLICTS_INSTALL=	fasta # bin/align

PLIST_FILES=	bin/align bin/width

do-install:
.for i in align width
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${i} ${STAGEDIR}${PREFIX}/bin)
.endfor

.include <bsd.port.mk>
