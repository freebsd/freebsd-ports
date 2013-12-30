# Created by: Stephon Chen <stephon@pixnet.tw>
# $FreeBSD$

PORTNAME=	SES
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	http://d36cz9buwru1tt.cloudfront.net/catalog/attachments/
PKGNAMEPREFIX=	p5-
DISTNAME=	ses-tools-2011-11-14

MAINTAINER=	stephon@gmail.com
COMMENT=	Perl module of Amazon Simple Email Services

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-libwww>=6:${PORTSDIR}/www/p5-libwww

NO_BUILD=	yes
USES=		perl5
USE_PERL5=	run
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/bin

PLIST_FILES=	bin/ses-get-stats.pl \
		bin/ses-send-email.pl \
		bin/ses-verify-email-address.pl \
		%%SITE_PERL%%/SES.pm

SCRIPTS=	ses-get-stats.pl ses-send-email.pl ses-verify-email-address.pl

NO_STAGE=	yes
post-extract:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e '1 s|/usr/bin/perl|${PERL}|' ${SCRIPTS}

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/SES.pm ${PREFIX}/${SITE_PERL_REL}/

.include <bsd.port.mk>
