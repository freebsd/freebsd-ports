# New ports collection makefile for:    p5-Clamd
# Date created:                         23 December 2008
# Whom:                                 pgollucci@p6m7g8.com
#
# $FreeBSD$
#

PORTNAME=	Clamd
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/M/MS/MSERGEANT
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Clamd - Connect to a local clamd service and send commands

RUN_DEPENDS=	clamd:${PORTSDIR}/security/clamav
BUILD_DEPENDS=	${RUN_DEPENDS}

MAKE_JOBS_SAFE=  yes

MAN3=	Clamd.3

PERL_CONFIGURE=	yes

PLIST_FILES=	%%SITE_PERL%%/Clamd.pm \
				%%SITE_PERL%%/%%PERL_ARCH%%/auto/Clamd/.packlist

PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Clamd

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
