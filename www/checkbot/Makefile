# New ports collection makefile for:	checkbot
# Date created:				2. Feb 1998
# Whom:	      				wosch@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	checkbot
PORTVERSION=	1.80
CATEGORIES=	www perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Checkbot%20${PORTVERSION}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A WWW link verifier, similar to momspider

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
 		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/Mail/Send.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/Time/Duration.pm:${PORTSDIR}/devel/p5-Time-Duration \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
 		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/Mail/Send.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/Time/Duration.pm:${PORTSDIR}/devel/p5-Time-Duration \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

MAN1=		checkbot.1
PERL_CONFIGURE=	yes

PLIST_FILES=	bin/checkbot ${SITE_PERL:S!${LOCALBASE}/!!}/${PERL_ARCH}/auto/checkbot/.packlist
PLIST_DIRS=	${SITE_PERL:S!${LOCALBASE}/!!}/${PERL_ARCH}/auto/checkbot

.include <bsd.port.mk>
