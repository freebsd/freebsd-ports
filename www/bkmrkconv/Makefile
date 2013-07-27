# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	bkmrkconv
PORTVERSION=	1.12
CATEGORIES=	www
MASTER_SITES=	http://www.bleb.org/software/bkmrkconv/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Netscape bookmarks.html converter

USE_PERL5=	yes
NO_BUILD=	yes

post-patch:
	@${FIND} ${WRKSRC} -name '*.pl' | ${XARGS} ${REINPLACE_CMD} -i '' -e \
		's|/usr/bin/perl|${PERL}|g ; \
		 s|%%PREFIX%%|${PREFIX}|g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bkmrkconv.pl ${PREFIX}/bin/bkmrkconv
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/utils/* ${DATADIR}
	@${MKDIR} ${DATADIR}/src
	${INSTALL_DATA} ${WRKSRC}/src.example/* ${DATADIR}/src
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
