# New ports collection makefile for:	XML::Sablotron
# Date created:		13 Nov 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-Sablotron
PORTVERSION= 	0.44
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

LIB_DEPENDS=	sablot.44:${PORTSDIR}/textproc/sablotron

USE_PERL5=	yes

MAN3=		XML::Sablotron.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL -d ${PREFIX} \
			PREFIX=${PREFIX} \
			CC="${CC}" \
			CCFLAGS="${CFLAGS}" \
			INSTALLSCRIPT=${PREFIX}/bin

.include <bsd.port.mk>
