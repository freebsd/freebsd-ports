# New ports collection makefile for:	Dancer-Plugin-DataFu
# Date created:		20 Dec 2010
# Whom:			Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	Dancer-Plugin-DataFu
PORTVERSION=	1.103070
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/A/AW/AWNCORP
PKGNAMEPREFIX=	p5-

MAINTAINER=	magik@roorback.net
COMMENT=	Dancer HTML Form and Grid/Table engine with Input Validation

RUN_DEPENDS=    p5-Dancer>=1.2:${PORTSDIR}/www/p5-Dancer \
                p5-Array-Unique>0:${PORTSDIR}/devel/p5-Array-Unique \
                p5-Data-Dumper-Concise>0:${PORTSDIR}/devel/p5-Data-Dumper-Concise \
                p5-File-ShareDir>0:${PORTSDIR}/devel/p5-File-ShareDir \
                p5-Hash-Merge>0:${PORTSDIR}/textproc/p5-Hash-Merge \
                p5-Oogly>=0.31:${PORTSDIR}/devel/p5-Oogly \
                p5-Template-Toolkit>0:${PORTSDIR}/www/p5-Template-Toolkit
BUILD_DEPENDS=  ${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	dancer-datafu.1
MAN3=	Dancer::Plugin::DataFu.3 \
	Dancer::Plugin::DataFu::Form.3 \
	Dancer::Plugin::DataFu::Grid.3

.include <bsd.port.mk>
