# New ports collection makefile for:	ubh
# Date created:			1 January 2002
# Whom:				John Holland <john@zoner.org>
#
# $FreeBSD$
#

PORTNAME=	ubh
PORTVERSION=	2.5
CATEGORIES=	news graphics
MASTER_SITES=	http://ubh.sourceforge.net/download/

MAINTAINER=	john@zoner.org
COMMENT=	Perl script to download and decode binaries posted to Usenet

RUN_DEPENDS=	\
	${SITE_PERL}/News/Newsrc.pm:${PORTSDIR}/news/p5-News-Newsrc \
	${SITE_PERL}/Net/NNTP.pm:${PORTSDIR}/net/p5-Net \
	${SITE_PERL}/Mail/Mailer.pm:${PORTSDIR}/mail/p5-Mail-Tools \
	${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
	${SITE_PERL}/MIME/Decoder.pm:${PORTSDIR}/mail/p5-MIME-Tools \
	${SITE_PERL}/${PERL_ARCH}/String/CRC32.pm:${PORTSDIR}/devel/p5-String-CRC32

NO_BUILD=	YES

pre-patch:
	@${MV} ${WRKSRC}/ubh ${WRKSRC}/ubh.old
	@${SED} -e '1,1s:/usr/bin/perl:${PERL5}:' \
		${WRKSRC}/ubh.old > ${WRKSRC}/ubh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ubh ${PREFIX}/bin
	${CP} -R ${WRKSRC}/examples ${PREFIX}/share/ubh
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ubh
	${INSTALL_DATA} ${WRKSRC}/doc/ubh.html ${PREFIX}/share/doc/ubh
.endif

.include <bsd.port.mk>
