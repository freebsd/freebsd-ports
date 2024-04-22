PORTNAME=	courieruserinfo
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	security mail
MASTER_SITES=	http://www.arda.homeunix.net/software-downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User account information retrieval utility
WWW=		http://www.arda.homeunix.net/store/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	courierauthconfig:security/courier-authlib-base
RUN_DEPENDS=	courierauthconfig:security/courier-authlib-base

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		gmake localbase

PLIST_FILES=	sbin/courieruserinfo share/man/man8/courieruserinfo.8.gz
PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '/chown root/d' ${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
