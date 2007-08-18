# New ports collection makefile for:	w3c-validator
# Date created:				13 September 2005
# Whom:					Naram Qashat <cyberbotx@cyberbotx.com>
#
# $FreeBSD$
#

PORTNAME=	validator
PORTVERSION=	0.8.1
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
		${SITE_PERL}/Net/IP.pm:${PORTSDIR}/net-mgmt/p5-Net-IP \
		${SITE_PERL}/${PERL_ARCH}/SGML/Parser/OpenSP.pm:${PORTSDIR}/textproc/p5-SGML-Parser-OpenSP \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML

NO_BUILD=	yes
USE_PERL5_RUN=	yes

SUB_FILES=	pkg-message validator.conf.sample

OPTIONS=	HTML_TIDY "Enable HTML Markup Cleaning" On

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires Perl 5.8.0 or better to run
.endif

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
	${MKDIR} ${PREFIX}/www/validator
	${MKDIR} ${PREFIX}/www/validator/htdocs
	${MKDIR} ${PREFIX}/www/validator/htdocs/config
	${MKDIR} ${PREFIX}/www/validator/htdocs/dev
	${MKDIR} ${PREFIX}/www/validator/htdocs/dev/autotest
	${MKDIR} ${PREFIX}/www/validator/htdocs/dev/tests
	${MKDIR} ${PREFIX}/www/validator/htdocs/docs
	${MKDIR} ${PREFIX}/www/validator/htdocs/images
	${MKDIR} ${PREFIX}/www/validator/htdocs/images/info_icons
	${MKDIR} ${PREFIX}/www/validator/htdocs/images/valid_icons
	${MKDIR} ${PREFIX}/www/validator/htdocs/misc
	${MKDIR} ${PREFIX}/www/validator/htdocs/scripts
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/IETF
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/ISO-HTML
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/REC-html32-19970114
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/REC-html40-19980424
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/REC-html401-19991224
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/REC-MathML2-20031021
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/REC-MathML2-20031021/html
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/REC-MathML2-20031021/iso8879
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/REC-MathML2-20031021/iso9573-13
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/REC-MathML2-20031021/mathml
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/REC-smil-19980615
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/REC-SMIL2-20051213
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/REC-smil20-20050107
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/REC-SVG-20010904
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/REC-SVG11-20030114
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/REC-xhtml-basic-20001219
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/REC-xhtml-print-20060920
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/REC-xhtml1-20020801
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/REC-xhtml11-20010531
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/WD-xhtml-basic-20060705
	${MKDIR} ${PREFIX}/www/validator/htdocs/sgml-lib/WD-XHTMLplusMathMLplusSVG-20020809
	${MKDIR} ${PREFIX}/www/validator/htdocs/source
	${MKDIR} ${PREFIX}/www/validator/htdocs/style
	${MKDIR} ${PREFIX}/www/validator/httpd
	${MKDIR} ${PREFIX}/www/validator/httpd/cgi-bin
	${MKDIR} ${PREFIX}/www/validator/share
	${MKDIR} ${PREFIX}/www/validator/share/templates
	${MKDIR} ${PREFIX}/www/validator/share/templates/en_US
	${INSTALL_DATA} `find ${WRKSRC}/htdocs -type f -depth 1` ${PREFIX}/www/validator/htdocs
	${INSTALL_DATA} ${WRKSRC}/htdocs/config/* ${PREFIX}/www/validator/htdocs/config
	${INSTALL_DATA} ${WRKSRC}/htdocs/dev/autotest/* ${PREFIX}/www/validator/htdocs/dev/autotest
	${INSTALL_DATA} ${WRKSRC}/htdocs/dev/tests/* ${PREFIX}/www/validator/htdocs/dev/tests
	${INSTALL_DATA} ${WRKSRC}/htdocs/docs/* ${PREFIX}/www/validator/htdocs/docs
	${INSTALL_DATA} `find ${WRKSRC}/htdocs/images -type f -depth 1` ${PREFIX}/www/validator/htdocs/images
	${INSTALL_DATA} ${WRKSRC}/htdocs/images/info_icons/* ${PREFIX}/www/validator/htdocs/images/info_icons
	${INSTALL_DATA} ${WRKSRC}/htdocs/images/valid_icons/* ${PREFIX}/www/validator/htdocs/images/valid_icons
	${INSTALL_DATA} ${WRKSRC}/htdocs/misc/* ${PREFIX}/www/validator/htdocs/misc
	${INSTALL_DATA} ${WRKSRC}/htdocs/scripts/* ${PREFIX}/www/validator/htdocs/scripts
	${INSTALL_DATA} `find ${WRKSRC}/htdocs/sgml-lib -type f -depth 1` ${PREFIX}/www/validator/htdocs/sgml-lib
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/IETF/* ${PREFIX}/www/validator/htdocs/sgml-lib/IETF
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/ISO-HTML/* ${PREFIX}/www/validator/htdocs/sgml-lib/ISO-HTML
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/REC-html32-19970114/* ${PREFIX}/www/validator/htdocs/sgml-lib/REC-html32-19970114
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/REC-html40-19980424/* ${PREFIX}/www/validator/htdocs/sgml-lib/REC-html40-19980424
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/REC-html401-19991224/* ${PREFIX}/www/validator/htdocs/sgml-lib/REC-html401-19991224
	${INSTALL_DATA} `find ${WRKSRC}/htdocs/sgml-lib/REC-MathML2-20031021 -type f -depth 1` ${PREFIX}/www/validator/htdocs/sgml-lib/REC-MathML2-20031021
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/REC-MathML2-20031021/html/* ${PREFIX}/www/validator/htdocs/sgml-lib/REC-MathML2-20031021/html
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/REC-MathML2-20031021/iso8879/* ${PREFIX}/www/validator/htdocs/sgml-lib/REC-MathML2-20031021/iso8879
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/REC-MathML2-20031021/iso9573-13/* ${PREFIX}/www/validator/htdocs/sgml-lib/REC-MathML2-20031021/iso9573-13
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/REC-MathML2-20031021/mathml/* ${PREFIX}/www/validator/htdocs/sgml-lib/REC-MathML2-20031021/mathml
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/REC-smil-19980615/* ${PREFIX}/www/validator/htdocs/sgml-lib/REC-smil-19980615
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/REC-SMIL2-20051213/* ${PREFIX}/www/validator/htdocs/sgml-lib/REC-SMIL2-20051213
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/REC-smil20-20050107/* ${PREFIX}/www/validator/htdocs/sgml-lib/REC-smil20-20050107
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/REC-SVG-20010904/* ${PREFIX}/www/validator/htdocs/sgml-lib/REC-SVG-20010904
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/REC-SVG11-20030114/* ${PREFIX}/www/validator/htdocs/sgml-lib/REC-SVG11-20030114
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/REC-xhtml-basic-20001219/* ${PREFIX}/www/validator/htdocs/sgml-lib/REC-xhtml-basic-20001219
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/REC-xhtml-print-20060920/* ${PREFIX}/www/validator/htdocs/sgml-lib/REC-xhtml-print-20060920
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/REC-xhtml1-20020801/* ${PREFIX}/www/validator/htdocs/sgml-lib/REC-xhtml1-20020801
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/REC-xhtml11-20010531/* ${PREFIX}/www/validator/htdocs/sgml-lib/REC-xhtml11-20010531
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/WD-xhtml-basic-20060705/* ${PREFIX}/www/validator/htdocs/sgml-lib/WD-xhtml-basic-20060705
	${INSTALL_DATA} ${WRKSRC}/htdocs/sgml-lib/WD-XHTMLplusMathMLplusSVG-20020809/* ${PREFIX}/www/validator/htdocs/sgml-lib/WD-XHTMLplusMathMLplusSVG-20020809
	${INSTALL_DATA} ${WRKSRC}/htdocs/source/* ${PREFIX}/www/validator/htdocs/source
	${INSTALL_DATA} ${WRKSRC}/htdocs/style/* ${PREFIX}/www/validator/htdocs/style
	${INSTALL_SCRIPT} ${WRKSRC}/httpd/cgi-bin/* ${PREFIX}/www/validator/httpd/cgi-bin
	${INSTALL_DATA} ${WRKSRC}/share/templates/en_US/* ${PREFIX}/www/validator/share/templates/en_US

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
