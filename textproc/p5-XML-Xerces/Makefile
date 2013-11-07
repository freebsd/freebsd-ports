# Created by: Ken Menzel <kenm@icarz.com>
# $FreeBSD$

PORTNAME=	XML-Xerces
PORTVERSION=	2.7.0
PORTREVISION?=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}-0

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The Perl API to the Apache project's Xerces XML parser

BUILD_DEPENDS=	${LOCALBASE}/bin/swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	libxerces-c.so.27:${PORTSDIR}/textproc/xerces-c2

MAKE_JOBS_UNSAFE=	yes

USES=		gmake perl5
USE_PERL5=	configure
CONFIGURE_ENV=	XERCES_LIB="${LOCALBASE}/lib" \
		XERCES_INCLUDE="${LOCALBASE}/include" \
		XERCES_DEVEL="yes" \
		CXX="${CXX}"

.include <bsd.port.mk>
