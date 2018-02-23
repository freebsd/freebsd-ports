# Created by: Naram Qashat <cyberbotx@cyberbotx.com>
# $FreeBSD$

PORTNAME=	validator
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1_3
DISTVERSIONSUFFIX=	-release
PORTREVISION=	4
CATEGORIES=	www

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Markup Validation Service from the World Wide Web Consortium (W3C)

LICENSE=	W3C2002
LICENSE_NAME=	W3C Software Notice and License (2002/12/31)
LICENSE_TEXT=	See https://www.w3.org/Consortium/Legal/2002/copyright-software-20021231
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	onsgmls:textproc/opensp \
		p5-CGI.pm>=0:www/p5-CGI.pm \
		p5-Config-General>=0:devel/p5-Config-General \
		p5-Encode-HanExtra>=0:chinese/p5-Encode-HanExtra \
		p5-Encode-JIS2K>=0:converters/p5-Encode-JIS2K \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-HTML-Encoding>=0:www/p5-HTML-Encoding \
		p5-HTML-Template>=0:www/p5-HTML-Template \
		p5-libwww>=5.817:www/p5-libwww \
		p5-JSON>=0:converters/p5-JSON \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-Net-IP>=0:net-mgmt/p5-Net-IP \
		p5-SGML-Parser-OpenSP>=0:textproc/p5-SGML-Parser-OpenSP \
		p5-URI>=0:net/p5-URI \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML

USE_GITHUB=	yes
GH_ACCOUNT=	w3c
GH_PROJECT=	markup-validator
USES=		perl5 shebangfix
NO_ARCH=	yes
NO_BUILD=	yes
USE_PERL5=	run
SHEBANG_FILES=	httpd/cgi-bin/check \
		httpd/cgi-bin/sendfeedback.pl

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	HTML_TIDY
OPTIONS_DEFAULT=HTML_TIDY
HTML_TIDY_DESC=	Enable HTML Markup Cleaning

HTML_TIDY_RUN_DEPENDS=	p5-HTML-Tidy>=0:textproc/p5-HTML-Tidy

post-patch:
	@${REINPLACE_CMD} -e 's|%%WWWDIR%%|${WWWDIR}|' \
		${WRKSRC}/htdocs/config/validator.conf \
		${WRKSRC}/httpd/cgi-bin/check \
		${WRKSRC}/httpd/cgi-bin/sendfeedback.pl \
		${WRKSRC}/httpd/conf/httpd.conf

pre-install:
	${MV} ${WRKSRC}/htdocs/config/validator.conf \
		${WRKSRC}/htdocs/config/validator.conf.sample
	${MV} ${WRKSRC}/httpd/conf/httpd.conf \
		${WRKSRC}/httpd/conf/httpd.conf.sample
	${FIND} ${WRKSRC} \( -name \*.bak -or -name \*.orig \) -delete

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/validator/htdocs
	${MKDIR} ${STAGEDIR}${PREFIX}/www/validator/httpd
	${MKDIR} ${STAGEDIR}${PREFIX}/www/validator/share
	(cd ${WRKSRC}/htdocs && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/htdocs/)
	(cd ${WRKSRC}/httpd && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/httpd/)
	(cd ${WRKSRC}/share && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/share/)

.include <bsd.port.mk>
