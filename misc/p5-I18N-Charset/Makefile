# New ports collection makefile for:    p5-I18N-Charset
# Date created:			26 December 1999
# Whom:	      			Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	I18N-Charset
PORTVERSION=	1.39.2
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/\1/}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Module which maps CharSet names to the names registered with IANA

BUILD_DEPENDS=	${SITE_PERL}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String \
		${SITE_PERL}/Unicode/MapUTF8.pm:${PORTSDIR}/converters/p5-Unicode-MapUTF8 \
		${SITE_PERL}/App/Info/Lib/Iconv.pm:${PORTSDIR}/devel/p5-App-Info
RUN_DEPENDS=	${BUILD_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/IO/Capture/Stderr.pm:${PORTSDIR}/devel/p5-IO-Capture

PERL_CONFIGURE=	YES

MAN3=		I18N::Charset.3

post-patch:
	@${PERL} -pi -e 's#\r$$##g' ${WRKSRC}/lib/I18N/Charset.pm

.include <bsd.port.mk>
