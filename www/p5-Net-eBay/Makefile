# New ports collection makefile for:	p5-Net-eBay
# Date created:				Sat May 27 13:25:11 UTC 2006
# Whom:	      				Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	Net-eBay
PORTVERSION=	0.53
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	Perl Interface to XML based eBay API

BUILD_DEPENDS=	${SITE_PERL}/Bundle/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/XML/Dumper.pm:${PORTSDIR}/textproc/p5-XML-Dumper \
		${SITE_PERL}/DateTime/Precise.pm:${PORTSDIR}/devel/p5-DateTime-Precise \
		${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install
PLIST_SUB+=	EXAMPLESDIR="share/examples/${PORTNAME}"

MAN3=		Net::eBay.3

pre-configure:
	${MKDIR} ${WRKSRC}/examples
	${MV} ${WRKSRC}/*.pl ${WRKSRC}/examples/

post-install:
.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
