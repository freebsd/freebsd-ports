# New ports collection makefile for:	checkbot
# Date created:				2. Feb 1998
# Whom:	      				wosch@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	checkbot
PORTVERSION=	1.73
CATEGORIES=	www perl5
MASTER_SITES=	http://degraaff.org/checkbot/ \
		http://wolfram.schneider.org/src/

MAINTAINER=	wosch@FreeBSD.org
COMMENT=	A WWW link verifier, similar like momspider

RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
 		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/Mail/Send.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
MAN1PREFIX=	${PREFIX}/share
.endif

.if ${OSVERSION} >= 502000
BROKEN=		"Broken pkg-plist"
.endif

MAN1=		checkbot.1
USE_PERL5=	YES
PERL_CONFIGURE=	yes

.include <bsd.port.post.mk>
