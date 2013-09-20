# Created by: Vivek Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	SCGI
PORTVERSION=	0.6
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VIPERCODE
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	SCGI server interface

USES=		perl5
USE_PERL5=	modbuild

MAN3=	SCGI.3 SCGI::Request.3

PLIST_FILES=	${SITE_PERL_REL}/SCGI.pm ${SITE_PERL_REL}/SCGI/Request.pm
PLIST_DIRS=	${SITE_PERL_REL}/SCGI

NO_STAGE=	yes
.include <bsd.port.mk>
