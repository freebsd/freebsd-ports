# $FreeBSD$

PORTNAME=	fluent-mixin-plaintextformatter
PORTVERSION=	0.2.2
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Fluentd plugin to include format values into json, tsv or csv

LICENSE=	APACHE20

RUN_DEPENDS=	\
	rubygem-fluentd>0:${PORTSDIR}/sysutils/rubygem-fluentd \
	rubygem-ltsv>0:${PORTSDIR}/textproc/rubygem-ltsv

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
