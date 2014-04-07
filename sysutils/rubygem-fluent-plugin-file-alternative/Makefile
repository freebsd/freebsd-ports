# $FreeBSD$

PORTNAME=	fluent-plugin-file-alternative
PORTVERSION=	0.1.4
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Gems for fluent plugin of alternative implementation of out_file

RUN_DEPENDS=	\
	rubygem-fluentd>0:${PORTSDIR}/sysutils/rubygem-fluentd \
	rubygem-fluent-mixin-plaintextformatter>0:${PORTSDIR}/sysutils/rubygem-fluent-mixin-plaintextformatter

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
