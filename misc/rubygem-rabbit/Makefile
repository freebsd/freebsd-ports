# Created by: TAKATSU Tomonari <tota@FreeBSD.org>

PORTNAME=	rabbit
PORTVERSION=	3.0.0
CATEGORIES=	misc rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	RD-document-based presentation application

LICENSE=	GPLv2+
LICENSE_FILE_GPLv2+ =	${WRKSRC}/GPL

RUN_DEPENDS=	rubygem-coderay>=1.0.0:textproc/rubygem-coderay \
		rubygem-faraday>0:www/rubygem-faraday \
		rubygem-gdk_pixbuf2>=3.0.9:graphics/rubygem-gdk_pixbuf2 \
		rubygem-gettext>=3.0.1:devel/rubygem-gettext \
		rubygem-gtk3>0:x11-toolkits/rubygem-gtk3 \
		rubygem-hikidoc>0:textproc/rubygem-hikidoc \
		rubygem-kramdown>0:textproc/rubygem-kramdown \
		rubygem-kramdown-parser-gfm>0:textproc/rubygem-kramdown-parser-gfm \
		rubygem-nokogiri>0:textproc/rubygem-nokogiri \
		rubygem-poppler>=3.2.5:x11-toolkits/rubygem-poppler \
		rubygem-rdtool>0:textproc/rubygem-rdtool \
		rubygem-rouge>0:textproc/rubygem-rouge \
		rubygem-rsvg2>=3.1.4:graphics/rubygem-rsvg2 \
		rubygem-rttool>0:textproc/rubygem-rttool

NO_ARCH=	yes
USES=		gem gettext
USE_RUBY=	yes
PLIST_FILES=	bin/rabbit bin/rabbirc bin/rabbit-command bin/rabbit-slide \
		bin/rabbit-theme

OPTIONS_DEFINE=	MIMETEX
MIMETEX_DESC=	Run with mimetex

MIMETEX_RUN_DEPENDS=	${LOCALBASE}/www/mimetex/cgi-bin/mimetex.cgi:www/mimetex

post-patch-MIMETEX-on:
	${REINPLACE_CMD} -e 's|"mimetex.cgi"|"${PREFIX}/www/mimetex/cgi-bin/mimetex.cgi"|' \
		${WRKSRC}/lib/rabbit/parser/ext/tex.rb

.include <bsd.port.mk>
