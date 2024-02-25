PORTNAME=	courierpasswd
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	security mail
MASTER_SITES=	http://www.arda.homeunix.net/software-downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User authentication and password changing utility
WWW=		http://www.arda.homeunix.net/downloads/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcourierauth.so:security/courier-authlib-base

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		gmake localbase

MINUID?=	100 # XXX: set this to 1000 for FreeBSD?

CONFIGURE_ARGS=	--with-minuid=${MINUID}

PLIST_FILES=	sbin/courierpasswd share/man/man8/courierpasswd.8.gz
PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README

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
