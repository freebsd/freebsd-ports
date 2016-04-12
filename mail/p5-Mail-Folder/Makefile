# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mail-Folder
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	MailFolder-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for a folder-independant interface to email folders

BUILD_DEPENDS=	p5-Mail-Tools>=0:mail/p5-Mail-Tools \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-File-Sync>=0:devel/p5-File-Sync \
		p5-MIME-Tools>=0:mail/p5-MIME-Tools
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-configure:
	@${PERL} -pi -e 's/^FULLEXT.*/FULLEXT=Mail\/Folder/' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
