# New ports collection makefile for:	mbx2mbox
# Version required:	0.2
# Date created:		23 November 1998
# Whom:			Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

DISTNAME=	mbx2mbox-0.2
CATEGORIES=	mail
MASTER_SITES=	http://www.cs.virginia.edu/~dwc3q/code/

NO_BUILD=	yes
USE_PERL5=	yes

post-patch:
	@${MV} ${WRKSRC}/mbx2mbox ${WRKSRC}/mbx2mbox.pre_sed
	@${SED} -e 's%/usr/bin/perl%${PERL}%' \
		${WRKSRC}/mbx2mbox.pre_sed > ${WRKSRC}/mbx2mbox

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mbx2mbox ${PREFIX}/bin/mbx2mbox
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mbx2mbox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mbx2mbox
.endif

.include <bsd.port.mk>
