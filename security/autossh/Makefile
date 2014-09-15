# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	autossh
PORTVERSION=	1.4d
CATEGORIES=	security
MASTER_SITES=	http://www.harding.motd.ca/autossh/
EXTRACT_SUFX=	.tgz

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Automatically restart SSH sessions and tunnels

GNU_CONFIGURE=	yes

PORTDOCS=	CHANGES README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,cp autossh.1 ,$$\{BSD_INSTALL_MAN\} autossh.1 ,g' ${WRKSRC}/${MAKEFILE}.in
	@${REINPLACE_CMD} -e 's,cp autossh ,$$\{BSD_INSTALL_PROGRAM\} autossh ,g' ${WRKSRC}/${MAKEFILE}.in
	@${REINPLACE_CMD} -e 's,cp ,$$\{BSD_INSTALL_DATA\} ,g' ${WRKSRC}/${MAKEFILE}.in
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -Ee '/doc/d' ${WRKSRC}/${MAKEFILE}.in
.endif

.include <bsd.port.mk>
