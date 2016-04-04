# Created by: Zane C, Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	ZConf-Mail
PORTVERSION=	2.0.0
PORTREVISION=	3
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Misc mail client functions backed by ZConf

BUILD_DEPENDS=	p5-Config-Tiny>=0:devel/p5-Config-Tiny \
		p5-Email-Date>=0:mail/p5-Email-Date \
		p5-Email-Simple>=0:mail/p5-Email-Simple \
		p5-File-MimeInfo>=0:devel/p5-File-MimeInfo \
		p5-IO-MultiPipe>=0:devel/p5-IO-MultiPipe \
		p5-MIME-Lite>=0:mail/p5-MIME-Lite \
		p5-Mail-Box>=0:mail/p5-Mail-Box \
		p5-Mail-IMAPTalk>=0:mail/p5-Mail-IMAPTalk \
		p5-Mail-POP3Client>=0:mail/p5-Mail-POP3Client \
		p5-Net-SMTP-TLS>=0:mail/p5-Net-SMTP-TLS \
		p5-Net-SMTP_auth>=0:mail/p5-Net-SMTP_auth \
		p5-Text-Autoformat>=0:textproc/p5-Text-Autoformat \
		p5-ZConf-GUI>=0:devel/p5-ZConf-GUI \
		p5-ZConf>=0:net/p5-ZConf
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/zcgetmail bin/zcmailaccount
USE_PERL5=	configure

.include <bsd.port.mk>
