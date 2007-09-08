# New ports collection makefile for:	p5-Net-Z3950
# Date created:				23 December 2001
# Whom:                			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Z3950
PORTVERSION=	0.51
CATEGORIES=	net perl5
MASTER_SITES=	http://perl.z3950.org/download/
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A perl interface to the Z39.50 information retrieval protocol

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Event.pm:${PORTSDIR}/devel/p5-Event
LIB_DEPENDS=	yaz.2:${PORTSDIR}/net/yaz
RUN_DEPENDS=	${SITE_PERL}/MARC/Record.pm:${PORTSDIR}/textproc/p5-MARC-Record \
		${SITE_PERL}/${PERL_ARCH}/Event.pm:${PORTSDIR}/devel/p5-Event

BROKEN=		Does not build

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}

MAN3=		Net::Z3950::ResultSet.3 Net::Z3950::Manager.3 \
		Net::Z3950::Tutorial.3 Net::Z3950::Record.3 \
		Net::Z3950::Connection.3 Net::Z3950::APDU.3 Net::Z3950.3 \
		Net::Z3950::ScanSet.3

CONFLICTS=	p5-Net-Z3950-ZOOM-[0-9]*

.include <bsd.port.mk>
