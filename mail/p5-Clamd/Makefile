# Created by: pgollucci@p6m7g8.com
# $FreeBSD$

PORTNAME=	Clamd
PORTVERSION=	1.04
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSERGEANT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Clamd - Connect to a local clamd service and send commands

RUN_DEPENDS=	clamd:${PORTSDIR}/security/clamav
BUILD_DEPENDS:=	${RUN_DEPENDS}

MAN3=	Clamd.3

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	%%SITE_PERL%%/Clamd.pm \
				%%SITE_PERL%%/%%PERL_ARCH%%/auto/Clamd/.packlist

PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Clamd

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
