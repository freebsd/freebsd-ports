# Created by: Andrew St. Jean <andrew@arda.homeunix.net>
# $FreeBSD$

PORTNAME=	courieruserinfo
PORTVERSION=	1.1.2
CATEGORIES=	security mail
MASTER_SITES=	http://www.arda.homeunix.net/software-downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User account information retrieval utility

BUILD_DEPENDS=	courierauthconfig:security/courier-authlib-base
RUN_DEPENDS=	courierauthconfig:security/courier-authlib-base

GNU_CONFIGURE=	yes
USES=		gmake
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	sbin/courieruserinfo man/man8/courieruserinfo.8.gz
PORTDOCS=	AUTHORS ChangeLog COPYING INSTALL NEWS README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '/chown root/d' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
