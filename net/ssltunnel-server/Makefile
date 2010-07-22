# ex:ts=8
# Ports collection makefile for:	ssltunnel-server
# Date created:			June 10, 2003
# Whom:				at@rominet.net
#
# $Id: Makefile,v 1.3 2003/09/21 16:20:44 thivillon Exp $
#
# $FreeBSD$
#

PORTNAME=	ssltunnel
PORTVERSION=	1.18
CATEGORIES=	net
MASTER_SITES=	http://www.hsc.fr/ressources/outils/ssltunnel/download/
PKGNAMESUFFIX=	-server

MAINTAINER=	utisoft@gmail.com
COMMENT=	PPP over SSL virtual private networking (server part)

LICENSE=	BSD
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-client

.include <bsd.port.pre.mk>

.if defined(WITH_TCPWRAPPERS)
CONFIGURE_ARGS+=	--with-libwrap
.endif

post-patch:
	@${REINPLACE_CMD} -e 's^#include <utmp.h>^/*utmp.h not for FreeBSD*/^' \
		${WRKSRC}/server/main.c \
		${WRKSRC}/server/pppwho.c \
		${WRKSRC}/server/sessions.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/LISEZ-MOI ${DOCSDIR}
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/server/pppserver.sh ${PREFIX}/etc/rc.d/ssltunnel.sh.sample
	${INSTALL_DATA} ${WRKSRC}/server/users ${PREFIX}/etc/ssltunnel/users.sample

.include <bsd.port.post.mk>
