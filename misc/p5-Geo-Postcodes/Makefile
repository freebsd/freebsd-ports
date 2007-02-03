# New ports collection makefile for:	p5-Geo-Postcodes
# Date created:		2006-07-19
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-Postcodes
PORTVERSION=	0.311
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Geo
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/\1/}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base class for the Geo::Postcodes::XX modules

PERL_CONFIGURE=	yes

MAN3=  		Geo::Postcodes.3 \
		Geo::Postcodes::Selection.3 \
		Geo::Postcodes::Subclass.3 \
		Geo::Postcodes::Tutorial.3 \
		Geo::Postcodes::Update.3

.include <bsd.port.mk>
