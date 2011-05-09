# New ports collection makefile for:    p5-SES
# Date created:         2011-04-29
# Whom:                 Stephon Chen <stephon@pixnet.tw>
#
# $FreeBSD$
#

PORTNAME=	SES
PORTVERSION=	1.00
CATEGORIES=	mail perl5
MASTER_SITES=	http://aws-catalog-download-files.s3.amazonaws.com/
PKGNAMEPREFIX=	p5-
DISTNAME=	Amazon${PORTNAME}-2011-03-03

MAINTAINER=	stephon@pixnet.tw
COMMENT=	Perl module of Amazon Simple Email Services

RUN_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA

NO_BUILD=	yes
USE_PERL5_RUN=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/bin

PLIST_FILES=	bin/ses-get-stats.pl \
		bin/ses-send-email.pl \
		bin/ses-verify-email-address.pl \
		%%SITE_PERL%%/SES.pm

SCRIPTS=	ses-get-stats.pl ses-send-email.pl ses-verify-email-address.pl

post-extract:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e '1 s|/usr/bin/perl|${PERL}|' ${SCRIPTS}

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/SES.pm ${PREFIX}/${SITE_PERL_REL}/

.include <bsd.port.mk>
