# New ports collection makefile for:    ack
# Date created:         19 Apr 2008
# Whom:                 Frank Steinborn <steinex@nognu.de>
#
# $FreeBSD$
#

PORTNAME=	ack
PORTVERSION=	1.82
CATEGORIES=	sysutils
MASTER_SITES=	http://ack.googlecode.com/svn/tags/1.82/
DISTFILES=	${PORTNAME}-standalone Changes README TODO \
		ack-help-types.txt ack-help.txt

MAINTAINER=	steinex@nognu.de
COMMENT=	grep-like tool aimed at programmers

NO_BUILD=	yes
USE_PERL5=	yes

PORTDOCS=	Changes README TODO ack-help-types.txt \
		ack-help.txt
PLIST_FILES=	bin/ack

do-extract:
	@${MKDIR} ${WRKDIR}
.for f in ${DISTFILES}
	@${CP} ${DISTDIR}/${f} ${WRKDIR}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ack-standalone ${PREFIX}/bin/ack
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
