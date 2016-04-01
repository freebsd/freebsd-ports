# Created by: Andy Gilligan
# $FreeBSD$

PORTNAME=	mb2md
PORTVERSION=	3.20
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://batleth.sapienti-sat.org/projects/mb2md/
DISTNAME=	${PORTNAME}-${PORTVERSION}.pl
EXTRACT_SUFX=	.gz

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Converts mbox mailboxes to Maildir

RUN_DEPENDS=	p5-TimeDate>=0:devel/p5-TimeDate

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/${PORTNAME}

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USES=		shebangfix perl5
SHEBANG_FILES=	mb2md

PLIST_FILES=	bin/mb2md

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
