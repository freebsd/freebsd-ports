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

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/File/Sync.pm:${PORTSDIR}/devel/p5-File-Sync
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/File/Sync.pm:${PORTSDIR}/devel/p5-File-Sync \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MIME/Head.pm:${PORTSDIR}/mail/p5-MIME-Tools

PERL_CONFIGURE=	YES

MAN3=		Mail::Folder.3 Mail::Folder::Emaul.3 Mail::Folder::Mbox.3 \
		Mail::Folder::NNTP.3 Mail::Folder::Maildir.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
