# ex:ts=8
# Ports collection makefile for:  foo
# Date created:			  Fri Mar 18, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	super
PORTVERSION=	3.14.0
CATEGORIES=	security sysutils
MASTER_SITES=	ftp://ftp.ucolick.org/pub/users/will/  \
		ftp://phobos.caltech.edu/users/will/  \
		ftp://ftp.infodrom.north.de/pub/unix/utilities/super/

MAINTAINER=	obrien@FreeBSD.org

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 300000
BROKEN=	'/usr/include/prot.h parse error'
.endif

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

.include <bsd.port.post.mk>
