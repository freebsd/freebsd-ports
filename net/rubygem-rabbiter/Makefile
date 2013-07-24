# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rabbiter
PORTVERSION=	2.0.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Rabbiter is a twitter client for Rabbit

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-gio2>=1.1.4:${PORTSDIR}/devel/rubygem-gio2 \
		rubygem-rabbit>=2.0.0:${PORTSDIR}/misc/rubygem-rabbit \
		rubygem-twitter_oauth>0:${PORTSDIR}/security/rubygem-twitter_oauth \
		rubygem-twitter-stream>=0.1.16:${PORTSDIR}/net/rubygem-twitter-stream

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rabbiter

.include <bsd.port.mk>
