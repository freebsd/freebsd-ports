# New ports collection makefile for:	intltool
# Date created:				19th January 2001
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/textproc/intltool/Makefile,v 1.13 2010/05/29 19:19:26 kwm Exp $

PORTNAME=	intltool
PORTVERSION=	0.41.1
CATEGORIES=	textproc gnome
MASTER_SITES=	http://launchpadlibrarian.net/41841194/
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tools to internationalize various kinds of data files

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

USE_GMAKE=	yes
USE_ICONV=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir="${PREFIX}/libdata"

MAN8=		intltool-extract.8 intltool-merge.8 intltool-prepare.8 \
		intltool-update.8 intltoolize.8

CONFLICTS=	xml-i18n-tools-[0-9]*

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} \
		-E -e '/^mkinstalldirs[[:space:]]*=/s^/\.\.^^g'

post-install:
	${MKDIR} ${PREFIX}/share/intltool/XML/Parser/Style
	${INSTALL_DATA} ${FILESDIR}/OrigTree.pm \
	    	${PREFIX}/share/intltool/XML/Parser/Style

.include <bsd.port.mk>
