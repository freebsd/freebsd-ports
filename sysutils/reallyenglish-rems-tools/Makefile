# New ports collection makefile for:	reallyenglish-rems-tools
# Date created:		2010-07-02
# Whom:			Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
#
# $FreeBSD$
#

PORTNAME=	reallyenglish-rems-tools
PORTVERSION=	0.14
#PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://dist.reallyenglish.com/${PORTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Local tools at reallyenglish, not available for public

RUN_DEPENDS=	${LOCALBASE}/sbin/send_nsca:${PORTSDIR}/net-mgmt/nsca-client

USE_PERL5=	Yes
MAKE_ARGS=	DESTDIR=${PREFIX}
USE_RC_SUBR=	varnisherrorlog

.include <bsd.port.mk>
