# New ports collection makefile for:   html2wml
# Date created:        15 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	html2wml
PORTVERSION=	0.4.0
CATEGORIES=	www
MASTER_SITES=	http://maddingue.free.fr/techie/download/Html2Wml/

MAINTAINER=	greid@ukug.uk.freebsd.org

RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Text/Template.pm:${PORTSDIR}/textproc/p5-Text-Template \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

USE_PERL5=	yes
SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

MAN1=		html2wml.1

do-build:
	cd ${BUILD_WRKSRC}/doc; \
	${LN} -sf readme.pod html2wml.pod; \
	pod2man --center="Html2Wml Documentation" \
		--release=0.4.0 html2wml.pod > html2wml.man

checkconfig:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} default

.include <bsd.port.mk>
