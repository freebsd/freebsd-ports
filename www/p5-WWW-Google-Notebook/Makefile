# New ports collection makefile for:	p5-WWW-Google-Notebook
# Date created:		2006-10-15
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Google-Notebook
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Perl interface for Google Notebook

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		WWW::Google::Notebook.3 WWW::Google::Notebook::Note.3 WWW::Google::Notebook::Notebook.3

.include <bsd.port.mk>
