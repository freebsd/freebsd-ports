# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	extract_url
PORTVERSION=	1.6.2
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Perl script that extracts URLs from email in MIME or plain text format

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-MIME-Tools>=0:mail/p5-MIME-Tools \
		p5-HTML-Parser>=0:www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake perl5
MAKE_ARGS=	all prefix=${PREFIX} man_prefix=${PREFIX}
SUB_FILES=	pkg-message
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	m3m0ryh0l3
GH_PROJECT=	extracturl

PLIST_FILES=	bin/extract_url \
		share/extract_url/extract_urlview.sample \
		man/man1/extract_url.1.gz
PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=		DOCS URI_FIND
OPTIONS_RADIO=		URL_SELECTOR
OPTIONS_RADIO_URL_SELECTOR=	CURSES_UI URLVIEW
OPTIONS_DEFAULT=	CURSES_UI URI_FIND
OPTIONS_SUB=		yes

CURSES_UI_DESC=		Allows it to fully replace urlview
URI_FIND_DESC=		Recognizes more exotic URL variations in plain text
URLVIEW_DESC=		Uses urlview for the URL selector menu

CURSES_UI_RUN_DEPENDS=	p5-Curses-UI>=0:devel/p5-Curses-UI
URLVIEW_RUN_DEPENDS=	urlview>=0:textproc/urlview
URI_FIND_RUN_DEPENDS=	p5-URI-Find>=0:textproc/p5-URI-Find

post-patch:
	@${REINPLACE_CMD} '/pod2man.mk/s|make|${MAKE_CMD}|' \
		${WRKSRC}/${MAKEFILE}

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}view.sample \
		${STAGEDIR}${DATADIR}/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
