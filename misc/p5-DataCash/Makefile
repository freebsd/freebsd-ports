# New ports collection makefile for:	DataCash-External
# Date created:				10 August 2001
# Whom:	      				Mark Murray <markm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DataCash-External
PORTVERSION=	2.9.0
CATEGORIES=	misc perl5
MASTER_SITES=	http://www.datacash.com/stronghold/perl/
PKGNAMEPREFIX=	p5-

MAINTAINER=	markm@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/FreezeThaw.pm:${PORTSDIR}/devel/p5-FreezeThaw \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Text/CSV.pm:${PORTSDIR}/devel/p5-Text-CSV
		
PERL_CONFIGURE=	yes

MAN3=		CCCheck.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
