# Created by: Andrew St. Jean <andrew@arda.homeunix.net>
# $FreeBSD$

PORTNAME=	courierpasswd
PORTVERSION=	1.1.3
CATEGORIES=	security mail
MASTER_SITES=	http://www.arda.homeunix.net/software-downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User authentication and password changing utility

LIB_DEPENDS=	libcourierauth.so:security/courier-authlib-base

GNU_CONFIGURE=	yes
USES=		gmake
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MINUID?=	100

CONFIGURE_ARGS+=	--with-minuid=${MINUID}

PLIST_FILES=	sbin/courierpasswd man/man8/courierpasswd.8.gz
PORTDOCS=	AUTHORS ChangeLog COPYING INSTALL NEWS README

OPTIONS_DEFINE=	DOCS

pre-fetch:
	@${ECHO} ""
	@${ECHO} "#############################################################"
	@${ECHO} ""
	@${ECHO} "  You should set the following build option."
	@${ECHO} ""
	@${ECHO} "  MINUID=uid"
	@${ECHO} "	Accounts with uids below this value cannot have"
	@${ECHO} "	their passwords changed. Default value is 100."
	@${ECHO} ""
	@${ECHO} "#############################################################"
	@${ECHO} ""

post-patch:
	@${REINPLACE_CMD} '/chown root/d' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
