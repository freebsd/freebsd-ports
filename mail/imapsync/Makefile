# New ports collection makefile for:	imapsync
# Date created:		14 Jan 2005
# Whom:			Alex Deiter <tiamat@komi.mts.ru>
#
# $FreeBSD$
#

PORTNAME=	imapsync
PORTVERSION=	1.172
CATEGORIES=	mail perl5
MASTER_SITES=	http://www.linux-france.org/prj/imapsync/dist/ \
		http://freebsd.komi.mtsnet.ru/ports/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tiamat@komi.mts.ru
COMMENT=	IMAP synchronization copy or migration tool

BUILD_DEPENDS=	${SITE_PERL}/Mail/IMAPClient.pm:${PORTSDIR}/mail/p5-Mail-IMAPClient \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/Digest/HMAC_MD5.pm:${PORTSDIR}/security/p5-Digest-HMAC
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/imapsync

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6 or newer. Install lang/perl5.8 and try again
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
