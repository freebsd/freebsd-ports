# ex:ts=8
# Ports collection makefile for:  foo
# Version required:     	  3.9.7
# Date created:			  Fri Mar 18, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.3 1998/11/23 09:02:19 asami Exp $
#

DISTNAME=	super-3.11.6
CATEGORIES=	security sysutils
MASTER_SITES=	ftp://phobos.caltech.edu/users/will/  \
		ftp://ftp.ucolick.org/pub/users/will/  \
		ftp://ftp.infodrom.north.de/pub/unix/utilities/super/

MAINTAINER=     obrien@FreeBSD.org

GNU_CONFIGURE=	yes
MAN1=		super.1 setuid.1
MAN5=		super.5

post-install:
	@strip ${PREFIX}/bin/super ${PREFIX}/bin/setuid
	@${MKDIR} ${PREFIX}/share/examples
	@${INSTALL_DATA} ${FILESDIR}/sample.tab ${PREFIX}/share/examples
	@${INSTALL_DATA} ${FILESDIR}/sample.cdmount ${PREFIX}/share/examples
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/super
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/super
.endif

.include <bsd.port.mk>
