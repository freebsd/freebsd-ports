# New ports collection makefile for:	Mathomatic
# Date created:			Tue Mar 22 10:05:25 CET 2005
# Whom:				Roman Neuhauser <neuhauser@sigpipe.cz>
#
# $FreeBSD$
#

PORTNAME=	mathomatic
PORTVERSION=	14.5.1
CATEGORIES=	math
MASTER_SITES=	http://www.panix.com/~gesslein/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Highly portable, general purpose CAS (Computer Algebra System)

USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes

MAKEFILE=	makefile
MAKE_ARGS=	-DREADLINE

PLIST_FILES=	bin/mathomatic
PORTDOCS=	*

MAN1=		mathomatic.1

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/ s|-O2||; /^LDFLAGS/ s|-s||' \
		${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mathomatic ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mathomatic.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/changes.txt ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
