# New ports collection makefile for:	p5-Mail-Folder
# Date created:				October 24th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mail-Folder
PORTVERSION=	0.07
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-
DISTNAME=	MailFolder-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module for a folder-independant interface to email folders

BUILD_DEPENDS=	${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/${PERL_ARCH}/File/Sync.pm:${PORTSDIR}/devel/p5-File-Sync \
		${SITE_PERL}/MIME/Head.pm:${PORTSDIR}/mail/p5-MIME-Tools
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Mail::Folder.3 Mail::Folder::Emaul.3 Mail::Folder::Mbox.3 \
		Mail::Folder::NNTP.3 Mail::Folder::Maildir.3

.include <bsd.port.mk>
