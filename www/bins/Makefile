# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bins
PORTVERSION=	1.1.29
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://download.gna.org/bins/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to generate HTML photo albums with XML support

RUN_DEPENDS=	\
	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
	convert:${PORTSDIR}/graphics/ImageMagick \
	p5-Text-Iconv>=0:${PORTSDIR}/converters/p5-Text-Iconv \
	p5-Text-Unaccent>=0:${PORTSDIR}/textproc/p5-Text-Unaccent \
	p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
	p5-HTML-Clean>0:${PORTSDIR}/www/p5-HTML-Clean \
	p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template \
	p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
	p5-Image-Info>=0:${PORTSDIR}/graphics/p5-Image-Info \
	p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size \
	p5-URI>=0:${PORTSDIR}/net/p5-URI \
	p5-XML-Grove>=0:${PORTSDIR}/textproc/p5-XML-Grove \
	p5-XML-Handler-YAWriter>=0:${PORTSDIR}/textproc/p5-XML-Handler-YAWriter \
	p5-libxml>=0:${PORTSDIR}/textproc/p5-libxml

USES=		tar:bzip2 perl5
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes

# additional scripts
BINS_SCRIPTS=	tools/bins_txt2xml
# doc file extension
DOC_EXTS=	html sgml xml

OPTIONS_DEFINE=	DOCS I18N
OPTIONS_DEFAULT=I18N
I18N_DESC=	Enable internationalization support

post-patch::
# perl PREFIX safeness
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 -x ${REINPLACE_CMD} -E \
		-e 's|/usr/bin/perl|${PERL}|'
# prefix safeness
	@${REINPLACE_CMD} -E \
		-e 's|(bins_edit=)".+"(.*)$$|\1"${PREFIX}/bin/bins_edit"\2|' \
		${WRKSRC}/tools/bins_txt2xml

do-install:
	@${SETENV} LOCALE=${PREFIX}/share/locale DESTDIR=${STAGEDIR} PREFIX=${PREFIX} RC=${PREFIX}/share/bins ${WRKSRC}/install.sh

post-install:
.for file in ${BINS_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for ext in ${DOC_EXTS}
	${INSTALL_DATA} ${WRKSRC}/doc/*.${ext} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.pre.mk>

##
## default for either pointyhat or unattended builds
##
.if defined(PACKAGE_BUILDING) || defined(BATCH)
post-patch::
	${REINPLACE_CMD} -e 's,read dummy,,' ${WRKSRC}/install.sh
.endif

EXTRA_PATCHES+=	${FILESDIR}/extra-patch-install.sh

# localization support
.if ${PORT_OPTIONS:MI18N}
RUN_DEPENDS+=	p5-Locale-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext
.endif

.include <bsd.port.post.mk>
