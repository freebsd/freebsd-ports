# New ports collection makefile for:	w3c-validator
# Date created:				13 September 2005
# Whom:					Naram Qashat <cyberbotx@cyberbotx.com>
#
# $FreeBSD$
#

PORTNAME=	validator
PORTVERSION=	1.2
CATEGORIES=	www
MASTER_SITES=	http://validator.w3.org/dist/ \
		http://www.cyberbotx.com/w3c-validator/
DISTFILES=	validator-${PORTVERSION:S/./_/g}.tar.gz sgml-lib-${PORTVERSION:S/./_/g}.tar.gz

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Markup Validation Service from the World Wide Web Consortium (W3C)

RUN_DEPENDS=	onsgmls:${PORTSDIR}/textproc/opensp \
		${SITE_PERL}/Config/General.pm:${PORTSDIR}/devel/p5-Config-General \
		${SITE_PERL}/${PERL_ARCH}/Encode/HanExtra.pm:${PORTSDIR}/chinese/p5-Encode-HanExtra \
		${SITE_PERL}/${PERL_ARCH}/Encode/JIS2K.pm:${PORTSDIR}/converters/p5-Encode-JIS2K \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/HTML/Encoding.pm:${PORTSDIR}/www/p5-HTML-Encoding \
		${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/Bundle/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/JSON.pm:${PORTSDIR}/converters/p5-JSON \
		${SITE_PERL}/Net/IP.pm:${PORTSDIR}/net-mgmt/p5-Net-IP \
		${SITE_PERL}/${PERL_ARCH}/SGML/Parser/OpenSP.pm:${PORTSDIR}/textproc/p5-SGML-Parser-OpenSP \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML

NO_BUILD=	yes
USE_PERL5_RUN=	5.8.0+

SUB_FILES=	pkg-message validator.conf.sample

OPTIONS=	HTML_TIDY "Enable HTML Markup Cleaning" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_HTML_TIDY)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/HTML/Tidy.pm:${PORTSDIR}/textproc/p5-HTML-Tidy
.endif

post-extract:
	@${RM} ${WRKSRC}/README.cvs
	@${RM} -rf ${WRKSRC}/misc
	@${RM} -rf ${WRKSRC}/httpd/conf
	@${RM} ${WRKSRC}/htdocs/config/validator.conf

pre-install:
	@${CP} ${WRKDIR}/validator.conf.sample ${WRKSRC}/htdocs/config/

do-install:
	${MKDIR} ${PREFIX}/www/validator/htdocs
	${MKDIR} ${PREFIX}/www/validator/httpd/cgi-bin
	${MKDIR} ${PREFIX}/www/validator/share
	(cd ${WRKSRC}/htdocs && ${COPYTREE_SHARE} \* ${PREFIX}/www/validator/htdocs/)
	${INSTALL_SCRIPT} ${WRKSRC}/httpd/cgi-bin/* ${PREFIX}/www/validator/httpd/cgi-bin
	(cd ${WRKSRC}/share && ${COPYTREE_SHARE} \* ${PREFIX}/www/validator/share/)

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
