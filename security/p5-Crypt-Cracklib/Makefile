# New ports collection makefile for:	Crypt-Cracklib
# Date created:				Fri Jan 26 20:26:11 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Crypt-Cracklib
PORTVERSION=	0.01
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to Alec Muffet's cracklib library

BUILD_DEPENDS=	${LOCALBASE}/lib/libcrack.a:${PORTSDIR}/security/cracklib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=INC="-I${LOCALBASE}/include"

MAN3=		Crypt::Cracklib.3

post-patch:
	${PERL} -pi -e "s@INCLUDE@${LOCALBASE}/include@g;\
			s@FBSDLIB@${LOCALBASE}/lib@g" ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
