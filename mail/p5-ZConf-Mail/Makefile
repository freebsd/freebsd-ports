# New ports collection makefile for:	p5-ZConf-Mail
# Date created:		2009-01-14
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	ZConf-Mail
PORTVERSION=	1.4.0
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Misc mail client functions backed by ZConf

RUN_DEPENDS=	${SITE_PERL}/Email/Simple.pm:${PORTSDIR}/mail/p5-Email-Simple \
		${SITE_PERL}/ZConf.pm:${PORTSDIR}/net/p5-ZConf \
		${SITE_PERL}/Email/Simple/Creator.pm:${PORTSDIR}/mail/p5-Email-Simple-Creator \
		${SITE_PERL}/Mail/IMAPTalk.pm:${PORTSDIR}/mail/p5-Mail-IMAPTalk \
		${SITE_PERL}/Mail/POP3Client.pm:${PORTSDIR}/mail/p5-Mail-POP3Client \
		${SITE_PERL}/Net/SMTP_auth.pm:${PORTSDIR}/mail/p5-Net-SMTP_auth \
		${SITE_PERL}/Net/SMTP/TLS.pm:${PORTSDIR}/mail/p5-Net-SMTP-TLS \
		${SITE_PERL}/Mail/Box.pm:${PORTSDIR}/mail/p5-Mail-Box \
		${SITE_PERL}/Curses/UI.pm:${PORTSDIR}/devel/p5-Curses-UI \
		${SITE_PERL}/IO/MultiPipe.pm:${PORTSDIR}/devel/p5-IO-MultiPipe \
    		${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite \
		${SITE_PERL}/File/MimeInfo/Magic.pm:${PORTSDIR}/devel/p5-File-MimeInfo \
		${SITE_PERL}/Email/Date.pm:${PORTSDIR}/mail/p5-Email-Date \
		${SITE_PERL}/mach/MIME/QuotedPrint.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/ZConf/GUI.pm:${PORTSDIR}/devel/p5-ZConf-GUI \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Mail/Cache.pm:${PORTSDIR}/mail/p5-Mail-Cache \
		${SITE_PERL}/Mail/IMAPTalk/MailCache.pm:${PORTSDIR}/mail/p5-Mail-IMAPTalk-MailCache \
		${SITE_PERL}/Text/SpellChecker/GUI.pm:${PORTSDIR}/textproc/p5-Text-SpellChecker-GUI

PERL_CONFIGURE=	yes

MAN3=		ZConf::Mail.3 \
		ZConf::Mail::GUI.3 \
		ZConf::Mail::GUI::Curses.3

.include <bsd.port.mk>
