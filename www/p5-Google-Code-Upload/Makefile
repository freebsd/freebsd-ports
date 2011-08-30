# New ports collection makefile for:	p5-Google-Code-Upload
# Date created:		2010-07-06
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=	Google-Code-Upload
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Uploading files to a Google Code project

BUILD_DEPENDS=	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN1=		googlecode_upload.pl.1
MAN3=		Google::Code::Upload.3

.include <bsd.port.mk>
