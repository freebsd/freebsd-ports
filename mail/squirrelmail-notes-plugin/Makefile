# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=		notes
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=		mail www
MASTER_SITES=	http://www.squirrelmail.org/plugins/
PKGNAMEPREFIX=	squirrelmail-
PKGNAMESUFFIX=	-plugin
DISTNAME=		${PORTNAME}.${PORTVERSION}-1.4.0
DIST_SUBDIR=	squirrelmail

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Allows you to create notes

USES=		perl5
USE_PERL5=	install
USE_SM_COMPAT=	yes

NO_STAGE=	yes

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.post.mk>
