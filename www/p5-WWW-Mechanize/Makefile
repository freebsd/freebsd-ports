# New ports collection makefile for:	www/p5-WWW-Mechanize
# Date created:				02 April 2003
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Mechanize
PORTVERSION=	1.50
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	This module is to help you automate interaction with a website

RUN_DEPENDS=	p5-HTML-Parser>=2.28:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-HTTP-Response-Encoding>=0.05:${PORTSDIR}/www/p5-HTTP-Response-Encoding \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=5.815:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE= yes
CONFIGURE_ARGS+=	--nolive

MAN3=		WWW::Mechanize.3 WWW::Mechanize::Cookbook.3 \
		WWW::Mechanize::Examples.3 WWW::Mechanize::FAQ.3 \
		WWW::Mechanize::Link.3 WWW::Mechanize::Image.3
MAN1=		mech-dump.1

.if !defined(NOPORTDOCS)
MYPORTDOCS=	Changes etc/www-mechanize-logo.png
PORTDOCS=	Changes www-mechanize-logo.png

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${MYPORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
