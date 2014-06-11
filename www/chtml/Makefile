# Created by: David Bushong <david+ports@bushong.net>
# $FreeBSD$

PORTNAME=	chtml
PORTVERSION=	0.0
PORTREVISION=	1
CATEGORIES=	www devel lang
MASTER_SITES=	http://people.delphiforums.com/gjc/
DISTNAME=	chtml
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chunked HTML templating engine

BUILD_DEPENDS=	${LOCALBASE}/bin/csiod:${PORTSDIR}/lang/siod

USES=		perl5
USE_PERL5=	run
MAKE_ENV=	SITE_PERL=${SITE_PERL}
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile

.include <bsd.port.mk>
