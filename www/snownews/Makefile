# ex:ts=8
# New ports collection makefile for:	snownews
# Date created:			Nov 3 2003
# Whom:				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	snownews
PORTVERSION=	1.5.12
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://kiza.kcore.de/media/software/snownews/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A text mode RSS newsreader

USE_PERL5_BUILD=yes
USE_GMAKE=	yes
USE_GNOME=	libxml2
HAS_CONFIGURE=	yes

OPTIONS=	OPML		"Outline Processor Markup Support" on

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITHOUT_OPML)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile
PLIST_SUB+=	OPML="@comment "
.else
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
PLIST_SUB+=	OPML=""
# opml2snow only have "" manpage
_MANPAGES+=	${PREFIX}/man/man1/opml2snow.1
.endif

MAN1=		snownews.1
MANLANG=	"" de nl fr it ru_RU.KOI8-R

post-patch:
	@${REINPLACE_CMD} -e 's|#!/usr/local/bin/perl|#!${PERL}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|ncurses|ncursesw|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|make|${GMAKE}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/Makefile
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e 's/ install-locales / /g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's/ locales$$//g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
