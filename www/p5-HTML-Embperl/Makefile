# New ports collection makefile for:	p5-HTML-Embperl
# Date created:				March 13, 2000
# Whom:	      				Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-Embperl
PORTVERSION= 	1.3b2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/p5-Apache

USE_PERL5=	yes

MAN3=		HTML::Embperl.3 HTML::EmbperlD.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
			${LOCALBASE}/sbin CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>
