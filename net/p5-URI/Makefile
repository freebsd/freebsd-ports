# New ports collection makefile for:    p5-URI
# Version required:                     1.*
# Date created:				1999/04/07
# Whom:					ache
#
# $FreeBSD$
#

DISTNAME=       URI-1.03
PKGNAME=        p5-URI-1.03
CATEGORIES=     net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=     URI

MAINTAINER=     ache@FreeBSD.org

BUILD_DEPENDS=  ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

USE_PERL5=      YES
MAN3=   \
	URI::WithBase.3 \
	URI::data.3 \
	URI::file.3 \
	URI::Heuristic.3 \
	URI::ldap.3 \
	URI::Escape.3 \
	URI.3 \
	URI::URL.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
