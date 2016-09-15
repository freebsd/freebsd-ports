# Created by: at@rominet.net
# $FreeBSD$

PORTNAME=	ssltunnel
PORTVERSION=	1.18
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.hsc.fr/ressources/outils/ssltunnel/download/
PKGNAMESUFFIX=	-server

MAINTAINER=	crees@FreeBSD.org
COMMENT=	PPP over SSL virtual private networking (server part)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	TCPWRAPPERS DOCS
TCPWRAPPERS_DESC=	libwrap support

TCPWRAPPERS_CONFIGURE_ON=	--with-libwrap

USES=		ssl
USE_RC_SUBR=	${PORTNAME}
SUB_FILES+=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-client
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

post-patch:
	@${REINPLACE_CMD} -e 's^#include <utmp.h>^/*utmp.h not for FreeBSD*/^' \
		${WRKSRC}/server/main.c \
		${WRKSRC}/server/pppwho.c \
		${WRKSRC}/server/sessions.c
	@${REINPLACE_CMD} -e 's^sbin/pppd^sbin/ppp^g' ${WRKSRC}/server/users
	@${AWK} '{print}/ppp/ { print "args -direct" }' \
		${WRKSRC}/server/users > ${WRKSRC}/server/users.new

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${ETCDIR}/tunnel.conf.default ${STAGEDIR}${ETCDIR}/tunnel.conf.sample
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/server.README
	${INSTALL_MAN} ${WRKSRC}/LISEZ-MOI ${STAGEDIR}${DOCSDIR}/server.LISEZ-MOI
	${INSTALL_DATA} ${WRKSRC}/server/users.new ${STAGEDIR}${ETCDIR}/users.sample

.include <bsd.port.mk>
