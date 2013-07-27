# Created by: Andrew St. Jean <andrew@arda.homeunix.net>
# $FreeBSD$

PORTNAME=	courieruserinfo
PORTVERSION=	1.1.2
CATEGORIES=	security mail
MASTER_SITES=	http://www.arda.homeunix.net/software-downloads/

MAINTAINER=	andrew@arda.homeunix.net
COMMENT=	User account information retrieval utility

BUILD_DEPENDS=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base
RUN_DEPENDS=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base

GNU_CONFIGURE=	yes
USES=		gmake
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN8=		courieruserinfo.8

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
