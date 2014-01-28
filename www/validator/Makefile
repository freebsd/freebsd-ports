# Created by: Naram Qashat <cyberbotx@cyberbotx.com>
# $FreeBSD$

PORTNAME=	validator
PORTVERSION=	1.3
CATEGORIES=	www
MASTER_SITES=	http://validator.w3.org/dist/ \
		http://www.cyberbotx.com/w3c-validator/
DISTFILES=	validator-${PORTVERSION:S/./_/g}.tar.gz sgml-lib-${PORTVERSION:S/./_/g}.tar.gz

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Markup Validation Service from the World Wide Web Consortium (W3C)

RUN_DEPENDS=	onsgmls:${PORTSDIR}/textproc/opensp \
		p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General \
		p5-Encode-HanExtra>=0:${PORTSDIR}/chinese/p5-Encode-HanExtra \
		p5-Encode-JIS2K>=0:${PORTSDIR}/converters/p5-Encode-JIS2K \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Encoding>=0:${PORTSDIR}/www/p5-HTML-Encoding \
		p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template \
		p5-libwww>=5.817:${PORTSDIR}/www/p5-libwww \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP \
		p5-SGML-Parser-OpenSP>=0:${PORTSDIR}/textproc/p5-SGML-Parser-OpenSP \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML

USES=		perl5 shebangfix
NO_BUILD=	yes
USE_PERL5=	run
SHEBANG_FILES=	httpd/cgi-bin/check \
		httpd/cgi-bin/sendfeedback.pl

SUB_FILES=	pkg-message validator.conf.sample

OPTIONS_DEFINE=	HTML_TIDY
OPTIONS_DEFAULT=HTML_TIDY
HTML_TIDY_DESC=	Enable HTML Markup Cleaning

HTML_TIDY_RUN_DEPENDS=	p5-HTML-Tidy>=0:${PORTSDIR}/textproc/p5-HTML-Tidy

post-extract:
	@${RM} ${WRKSRC}/README.cvs
	@${RM} -rf ${WRKSRC}/misc
	@${RM} -rf ${WRKSRC}/httpd/conf
	@${RM} ${WRKSRC}/htdocs/config/validator.conf

pre-install:
	${CP} -f ${WRKDIR}/validator.conf.sample ${WRKSRC}/htdocs/config/

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/validator/htdocs
	${MKDIR} ${STAGEDIR}${PREFIX}/www/validator/httpd/cgi-bin
	${MKDIR} ${STAGEDIR}${PREFIX}/www/validator/share
	(cd ${WRKSRC}/htdocs && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/validator/htdocs/)
	${INSTALL_SCRIPT} ${WRKSRC}/httpd/cgi-bin/* ${STAGEDIR}${PREFIX}/www/validator/httpd/cgi-bin
	(cd ${WRKSRC}/share && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/validator/share/)

.include <bsd.port.mk>
