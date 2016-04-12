# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	extract_url
PORTVERSION=	1.5.8
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	extracturl

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Perl script that extracts URLs from email in MIME or plain text format

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	p5-MIME-Tools>=0:mail/p5-MIME-Tools \
		p5-HTML-Parser>=0:www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake perl5
MAKE_ARGS=	all prefix=${PREFIX} man_prefix=${PREFIX}

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/extract_url \
		etc/extract_urlview.sample \
		man/man1/extract_url.1.gz

SUB_FILES=	pkg-message

OPTIONS_DEFINE=			DOCS GETOPT_LONG URI_FIND
OPTIONS_RADIO=			URL_SELECTOR
OPTIONS_RADIO_URL_SELECTOR=	CURSES_UI URLVIEW
OPTIONS_DEFAULT=		CURSES_UI GETOPT_LONG URI_FIND

CURSES_UI_DESC=		Allows it to fully replace urlview
GETOPT_LONG_DESC=	Recognizes long options --version and --list
URI_FIND_DESC=		Recognizes more exotic URL variations in plain text
URLVIEW_DESC=		Uses urlview for the URL selector menu

OPTIONS_SUB=	yes

CURSES_UI_RUN_DEPENDS=		p5-Curses-UI>=0:devel/p5-Curses-UI
GETOPT_LONG_RUN_DEPENDS=	p5-Getopt-Long>=0:devel/p5-Getopt-Long
URLVIEW_RUN_DEPENDS=		urlview>=0:textproc/urlview
URI_FIND_RUN_DEPENDS=		p5-URI-Find>=0:textproc/p5-URI-Find

PORTDOCS=	AUTHORS NEWS README

post-patch:
	@${REINPLACE_CMD} '/pod2man.mk/s|make|${MAKE_CMD}|' \
		${WRKSRC}/${MAKEFILE}

post-install:
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}view \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}view.sample

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
