# New ports collection makefile for:	wbl
# Date created:		2006-07-15
# Whom:			Renato Botelho <garga@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wbl
PORTVERSION=	1.1
CATEGORIES=	mail
MASTER_SITES=	http://www.technocage.com/~caskey/wbl/download/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Simple tool to manage white/black list on qmail

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
USE_QMAIL_RUN=	yes
NO_BUILD=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	CHANGELOG COPYING README
PLIST_FILES=	bin/wbl

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL},' \
			  -e 's,/var/qmail,${QMAIL_PREFIX},g' \
			  -e 's,/bin/cat,${CAT},g' \
		${WRKSRC}/wbl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wbl ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
