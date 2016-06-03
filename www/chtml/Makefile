# Created by: David Bushong <david+ports@bushong.net>
# $FreeBSD$

PORTNAME=	chtml
PORTVERSION=	0.0
PORTREVISION=	2
CATEGORIES=	www devel lang
MASTER_SITES=	http://people.delphiforums.com/gjc/
DISTNAME=	chtml

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chunked HTML templating engine

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/bin/csiod:lang/siod

USES=		perl5 tar:tgz
USE_PERL5=	run
MAKE_ENV=	SITE_PERL=${PREFIX}/${SITE_PERL_REL}
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
