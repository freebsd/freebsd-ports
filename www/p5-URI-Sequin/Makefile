# New ports collection makefile for:	www/p5-URI-Sequin
# Date created:				25 April 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	URI-Sequin
PORTVERSION=	1.1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	URI
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

WRKSRC=		${WRKDIR}/sequin-${PORTVERSION}
PERL_CONFIGURE=	yes

MAN3=		URI::Sequin.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-patch:
	@${PERL} -pi -e \
		's|\);$$|PM=>{q!Sequin.pm!=>q!\$$(INST_LIBDIR)/Sequin.pm!});|' \
		${WRKSRC}/Makefile.PL

post-install:
	@${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/URI/Sequin/examples
	@${INSTALL_DATA} ${WRKSRC}/example.pl ${WRKSRC}/ref?.log \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/URI/Sequin/examples

.include <bsd.port.mk>
