PORTNAME=	sortmail
PORTVERSION=	1.20
CATEGORIES=	mail
MASTER_SITES=	http://www.freebsdcluster.org/~lasse/software/

MAINTAINER=	lasse@freebsdcluster.org
COMMENT=	Useful tool for sorting mbox style mailboxes after date

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
.for f in recomposemail decomposemail sortmail
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
