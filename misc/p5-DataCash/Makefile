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

MAINTAINER=	ports@freebsd-services.com

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/FreezeThaw.pm:${PORTSDIR}/devel/p5-FreezeThaw \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Crypt/Blowfish.pm:${PORTSDIR}/security/p5-Crypt-Blowfish \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Text/CSV.pm:${PORTSDIR}/textproc/p5-Text-CSV
		
PERL_CONFIGURE=	yes

MAN3=		CCCheck.3 \
		DataCash::External.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-extract:
	find ${WRKSRC} -type f -exec perl -spi -e 's/\r//g' {} ';'

.include <bsd.port.mk>
