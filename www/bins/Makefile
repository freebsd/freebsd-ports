# New ports collection makefile for:	bins
# Date created:		Sat Nov 23 01:17:35 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bins
PORTVERSION=	1.1.20
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://jsautret.free.fr/BINS/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to generate HTML photo albums with XML support

RUN_DEPENDS=	\
	${PBASE}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
	${PBASE}/${PERL_ARCH}/Image/Magick.pm:${PORTSDIR}/graphics/ImageMagick \
	${PBASE}/${PERL_ARCH}/Text/Iconv.pm:${PORTSDIR}/converters/p5-Text-Iconv \
	${PBASE}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
	${PBASE}/HTML/Clean.pm:${PORTSDIR}/www/p5-HTML-Clean \
	${PBASE}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
	${PBASE}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String \
	${PBASE}/Image/Info.pm:${PORTSDIR}/graphics/p5-Image-Info \
	${PBASE}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size \
	${PBASE}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
	${PBASE}/XML/Grove.pm:${PORTSDIR}/textproc/p5-XML-Grove \
	${PBASE}/XML/Handler/YAWriter.pm:${PORTSDIR}/textproc/p5-XML-Handler-YAWriter \
	${PBASE}/XML/Parser/PerlSAX.pm:${PORTSDIR}/textproc/p5-libxml

IS_INTERACTIVE=	yes
USE_BZIP2=	yes
USE_PERL5_RUN=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes

# perlbase
PBASE=	${SITE_PERL}

# additional scripts
BINS_SCRIPTS=	bins_txt2xml
# doc file extension
DOC_EXTS=	html sgml xml

MAN1=	bins-edit-gui.1 bins.1 bins_edit.1

post-patch:
# perl PREFIX safeness
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 -x ${REINPLACE_CMD} -E \
		-e 's|/usr/bin/perl|${PERL}|'
# prefix safeness
	@${REINPLACE_CMD} -E \
		-e 's|(bins_edit=)".+"(.*)$$|\1"${PREFIX}/bin/bins_edit"\2|' \
		${WRKSRC}/bins_txt2xml

do-install:
	@${SETENV} PREFIX=${PREFIX} RC=${PREFIX}/share/bins ${WRKSRC}/install.sh

post-install:
.for file in ${BINS_SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ext in ${DOC_EXTS}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.${ext} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

##
## this port requires PERL 5.6.x or later
##
.if !(exists(${LOCALBASE}/bin/perl5.6.0) || exists(${LOCALBASE}/bin/perl5.6.1))
IGNORE=	Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

##
## default for either bento or unattended builds
##
.ifdef(BATCH)
WITH_I18N=yes
.endif

##
## Local options
##
# gui
.ifdef(WITH_GUI)
RUN_DEPENDS+=	\
	${PBASE}/${PERL_ARCH}/Gnome.pm:${PORTSDIR}/x11-toolkits/p5-Gnome \
	${PBASE}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk \
	${PBASE}/${PERL_ARCH}/Gtk/Gdk/ImlibImage.pm:${PORTSDIR}/x11-toolkits/p5-GdkImlib \
	${PBASE}/${PERL_ARCH}/Gtk/GladeXML.pm:${PORTSDIR}/x11-toolkits/p5-Glade \
	${PBASE}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM \
	${PBASE}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer \
	${PBASE}/XML/XQL.pm:${PORTSDIR}/textproc/p5-XML-XQL

PLIST_SUB=	GUI=""
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-install.sh

PLIST_SUB=	GUI="@comment "
.endif
# localization support
.ifdef(WITH_I18N)
RUN_DEPENDS+=	\
	${PBASE}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext
.endif

pre-everything::
.ifndef(WITH_GUI)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_GUI to enable a libglade GUI'
.endif
.ifndef(WITH_I18N)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_I18N to enable localization support.'
	@${ECHO_MSG} '===>   Support for languages other than english.'
.endif
	@${ECHO_MSG} '===>'

.include <bsd.port.post.mk>
