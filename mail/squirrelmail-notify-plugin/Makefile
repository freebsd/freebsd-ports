# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=		notify
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=		mail www
MASTER_SITES=	http://www.squirrelmail.org/plugins/
PKGNAMEPREFIX=	squirrelmail-
PKGNAMESUFFIX=	-plugin
DISTNAME=		${PORTNAME}_${PORTVERSION:S/./_/g}
DIST_SUBDIR=	squirrelmail

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Notify when new mail arrives

USES=		perl5
USE_PERL5=	install
USE_SM_COMPAT=	yes

NO_STAGE=	yes

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.post.mk>
