# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rabbit
PORTVERSION=	2.1.1
CATEGORIES=	misc rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	RD-document-based presentation application

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-coderay>=1.0.0:${PORTSDIR}/textproc/rubygem-coderay \
		rubygem-faraday>0:${PORTSDIR}/www/rubygem-faraday \
		rubygem-gettext>0:${PORTSDIR}/devel/rubygem-gettext \
		rubygem-gtk2>0:${PORTSDIR}/x11-toolkits/rubygem-gtk2 \
		rubygem-hikidoc>0:${PORTSDIR}/textproc/rubygem-hikidoc \
		rubygem-kramdown>0:${PORTSDIR}/textproc/rubygem-kramdown \
		rubygem-nokogiri>0:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-poppler>0:${PORTSDIR}/x11-toolkits/rubygem-poppler \
		rubygem-rdtool>0:${PORTSDIR}/textproc/rubygem-rdtool \
		rubygem-rsvg2>0:${PORTSDIR}/graphics/rubygem-rsvg2 \
		rubygem-rttool>0:${PORTSDIR}/textproc/rubygem-rttool

USES=		gettext
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rabbit bin/rabbirc bin/rabbit-command bin/rabbit-slide \
		bin/rabbit-theme

OPTIONS_DEFINE=	MIMETEX
MIMETEX_DESC=	Run with mimetex

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMIMETEX}
RUN_DEPENDS+=	${LOCALBASE}/www/mimetex/cgi-bin/mimetex.cgi:${PORTSDIR}/www/mimetex
.endif

.if ${PORT_OPTIONS:MMIMETEX}
post-patch:
	${REINPLACE_CMD} -e 's|"mimetex.cgi"|"${PREFIX}/www/mimetex/cgi-bin/mimetex.cgi"|' \
		${WRKSRC}/lib/rabbit/parser/ext/tex.rb
.endif

.include <bsd.port.mk>
