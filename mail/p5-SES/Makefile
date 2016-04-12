# Created by: Stephon Chen <stephon@pixnet.tw>
# $FreeBSD$

PORTNAME=	SES
PORTVERSION=	1.01
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	http://d36cz9buwru1tt.cloudfront.net/catalog/attachments/
PKGNAMEPREFIX=	p5-
DISTNAME=	ses-tools-2011-11-14

MAINTAINER=	stephon@gmail.com
COMMENT=	Perl module of Amazon Simple Email Services

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-URI>=0:net/p5-URI \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-libwww>=6:www/p5-libwww

USES=		perl5 shebangfix zip
NO_BUILD=	yes
USE_PERL5=	run

WRKSRC=		${WRKDIR}/bin

PLIST_FILES=	bin/ses-get-stats.pl \
		bin/ses-send-email.pl \
		bin/ses-verify-email-address.pl \
		%%SITE_PERL%%/SES.pm
SHEBANG_FILES=	*.pl

SCRIPTS=	ses-get-stats.pl ses-send-email.pl ses-verify-email-address.pl

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL_DATA} ${WRKSRC}/SES.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}

.include <bsd.port.mk>
