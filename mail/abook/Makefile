# Created by: Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
# $FreeBSD$

PORTNAME=	abook
PORTVERSION=	0.6.1
CATEGORIES=	mail
MASTER_SITES=	http://abook.sourceforge.net/devel/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Addressbook program with mutt mail client support

LICENSE=	GPLv2

USES=		ncurses readline gettext-tools autoreconf localbase
GNU_CONFIGURE=	yes

PORTDOCS=	ANNOUNCE AUTHORS BUGS ChangeLog FAQ INSTALL NEWS README \
		THANKS TODO

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
