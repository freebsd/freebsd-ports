# ex:ts=8
# Ports collection makefile for:  foo
# Version required:     	  3.9.7
# Date created:			  Fri Mar 18, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.2 1997/01/25 18:08:40 obrien Exp $
#

DISTNAME=	super-3.9.7
CATEGORIES=	security sysutils
MASTER_SITES=	ftp://phobos.caltech.edu/users/will/
EXTRACT_SUFX=	.shar.gz

MAINTAINER=     obrien@NUXI.com

EXTRACT_CMD=	zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sed -e '1,/Cut Here/d'|sh
MAN1=		super.1 setuid.1
MAN5=		super.5


post-install:
	@strip ${PREFIX}/bin/super ${PREFIX}/bin/setuid
	@${MKDIR} ${PREFIX}/share/examples
	@${INSTALL} ${WRKSRC}/sample.tab ${PREFIX}/share/examples
	@${INSTALL} ${WRKSRC}/sample.cdmount ${PREFIX}/share/examples
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/super
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/super
.endif

.include <bsd.port.mk>
