PORTNAME=	abook
PORTVERSION=	0.6.2
PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	http://abook.sourceforge.net/devel/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Addressbook program with mutt mail client support
WWW=		http://abook.sourceforge.net/

LICENSE=	GPLv3

USES=		autoreconf gettext-tools localbase ncurses readline
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

WRKSRC=		${WRKDIR}

PORTDOCS=	ANNOUNCE AUTHORS BUGS ChangeLog FAQ INSTALL NEWS README THANKS \
		TODO

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
