# Created by: Naram Qashat <cyberbotx@cyberbotx.com>
# $FreeBSD$

PORTNAME=	validator
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://validator.w3.org/dist/ \
		http://www.cyberbotx.com/w3c-validator/
DISTFILES=	validator-${PORTVERSION:S/./_/g}.tar.gz sgml-lib-${PORTVERSION:S/./_/g}.tar.gz

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Markup Validation Service from the World Wide Web Consortium (W3C)

RUN_DEPENDS=	onsgmls:textproc/opensp \
		p5-Config-General>=0:devel/p5-Config-General \
		p5-Encode-HanExtra>=0:chinese/p5-Encode-HanExtra \
		p5-Encode-JIS2K>=0:converters/p5-Encode-JIS2K \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-HTML-Encoding>=0:www/p5-HTML-Encoding \
		p5-HTML-Template>=0:www/p5-HTML-Template \
		p5-libwww>=5.817:www/p5-libwww \
		p5-JSON>=0:converters/p5-JSON \
		p5-Net-IP>=0:net-mgmt/p5-Net-IP \
		p5-SGML-Parser-OpenSP>=0:textproc/p5-SGML-Parser-OpenSP \
		p5-URI>=0:net/p5-URI \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML

USES=		perl5 shebangfix
NO_BUILD=	yes
USE_PERL5=	run
SHEBANG_FILES=	httpd/cgi-bin/check \
		httpd/cgi-bin/sendfeedback.pl

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	HTML_TIDY
OPTIONS_DEFAULT=HTML_TIDY
HTML_TIDY_DESC=	Enable HTML Markup Cleaning

HTML_TIDY_RUN_DEPENDS=	p5-HTML-Tidy>=0:textproc/p5-HTML-Tidy

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 502200
RUN_DEPENDS+=	p5-CGI.pm>=0:www/p5-CGI.pm
.endif

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

.include <bsd.port.post.mk>
