# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	snownews
PORTVERSION=	1.5.12
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://kiza.kcore.de/media/software/snownews/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A text mode RSS newsreader

USE_PERL5_BUILD=yes
USES=		gmake iconv
USE_GNOME=	libxml2
HAS_CONFIGURE=	yes

OPTIONS_DEFINE=	OPML NLS
OPTIONS_DEFAULT=	OPML
OPML_DESC=		Outline Processor Markup Support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ! ${PORT_OPTIONS:MOPML}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile
PLIST_SUB+=	OPML="@comment "
.else
RUN_DEPENDS=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML
PLIST_SUB+=	OPML=""
# opml2snow only have "" manpage
_MANPAGES+=	${PREFIX}/man/man1/opml2snow.1
.endif

MAN1=		snownews.1
MANLANG=	"" de nl fr it ru_RU.KOI8-R

post-patch:
	@${REINPLACE_CMD} -e 's|#!/usr/local/bin/perl|#!${PERL}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|ncurses|ncursesw|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-liconv|${ICONV_LIB}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|make|${GMAKE}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/Makefile
.if ! ${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e 's/ install-locales / /g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's/ locales$$//g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
