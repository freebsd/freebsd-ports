# New ports collection makefile for:	mbx2mbox
# Version required:	0.1
# Date created:		23 November 1998
# Whom:			Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

DISTNAME=	mbx2mbox-0.1
CATEGORIES=	mail
MASTER_SITES=	http://www.cs.virginia.edu/~dwc3q/code/ \
		ftp://maroon.webmaster.com/pub/mbx2mbox/
EXTRACT_SUFX=

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS= .
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_PERL5=	yes

post-patch:

	@${MV} ${WRKSRC}/${DISTNAME} ${WRKSRC}/${DISTNAME}.pre_sed
	@${SED} -e 's%/usr/bin/perl%${PERL}%' \
	${WRKSRC}/${DISTNAME}.pre_sed > ${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/mbx2mbox-0.1 ${PREFIX}/bin/mbx2mbox

.include <bsd.port.mk>
