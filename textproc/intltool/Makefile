# New ports collection makefile for:	intltool
# Date created:				19th January 2001
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	intltool
PORTVERSION=	0.31.2
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.31
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Xml internationalization support for GNOME, and others

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_PERL5=	yes
USE_GNOME=	gnometarget
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir="${PREFIX}/libdata"

MAN8=		intltool-extract.8 intltool-merge.8 intltool-prepare.8 \
		intltool-update.8 intltoolize.8

CONFLICTS=	xml-i18n-tools-*

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} \
		-E -e '/^mkinstalldirs[[:space:]]*=/s^/\.\.^^g'

post-install:
	${MKDIR} ${PREFIX}/share/intltool/XML/Parser/Style
	${INSTALL_DATA} ${FILESDIR}/OrigTree.pm \
		${PREFIX}/share/intltool/XML/Parser/Style

.include <bsd.port.mk>
