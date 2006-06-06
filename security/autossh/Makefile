# New ports collection makefile for:	autossh
# Date created:				26 December 2002
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	autossh
PORTVERSION=	1.4
CATEGORIES=	security
MASTER_SITES=	http://www.harding.motd.ca/autossh/
EXTRACT_SUFX=	.tgz

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Automatically restart SSH sessions and tunnels

GNU_CONFIGURE=	yes

PORTDOCS=	CHANGES README
MAN1=		autossh.1

post-patch:
	@${REINPLACE_CMD} -e 's,cp autossh.1 ,$$\{BSD_INSTALL_MAN\} autossh.1 ,g' ${WRKSRC}/${MAKEFILE}.in
	@${REINPLACE_CMD} -e 's,cp autossh ,$$\{BSD_INSTALL_PROGRAM\} autossh ,g' ${WRKSRC}/${MAKEFILE}.in
	@${REINPLACE_CMD} -e 's,cp ,$$\{BSD_INSTALL_DATA\} ,g' ${WRKSRC}/${MAKEFILE}.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -Ee 's,(.*doc.*),#\1,g' ${WRKSRC}/${MAKEFILE}.in
.endif

post-configure:
	@${REINPLACE_CMD} -e 's,exec_prefix,EXEC_PREFIX,g' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's,prefix,PREFIX,g' ${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
