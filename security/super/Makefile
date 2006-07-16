# ex:ts=8
# Ports collection makefile for:  super
# Date created:			  Fri Mar 18, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	super
PORTVERSION=	3.26.1
CATEGORIES=	security sysutils
MASTER_SITES=	ftp://ftp.ucolick.org/pub/users/will/
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	babak@farrokhi.net
COMMENT=	Allow others to run commands as root

GNU_CONFIGURE=	yes
MAN1=		super.1 setuid.1
MAN5=		super.5

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/super ${PREFIX}/bin/setuid
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${FILESDIR}/sample.tab ${FILESDIR}/sample.cdmount \
		${WRKSRC}/barebones.tab ${EXAMPLESDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
