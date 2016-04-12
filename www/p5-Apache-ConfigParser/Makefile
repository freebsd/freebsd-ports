# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Apache-ConfigParser
PORTVERSION=	1.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Load Apache configuration files

BUILD_DEPENDS=	p5-File-FnMatch>=0:devel/p5-File-FnMatch \
		p5-Tree-DAG_Node>=0:devel/p5-Tree-DAG_Node
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
