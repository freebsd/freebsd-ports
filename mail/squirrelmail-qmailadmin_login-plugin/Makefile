# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=		qmailadmin_login
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=		mail www
DISTNAME=		${PORTNAME}-${PORTVERSION}-1.4.3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Using the QmailAdmin cgi interface from SquirrelMail

RUN_DEPENDS=	${PREFIX}/www/cgi-bin.default/qmailadmin/qmailadmin:${PORTSDIR}/mail/qmailadmin

USE_GENERIC_PKGMESSAGE=	yes

NO_STAGE=	yes

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.post.mk>
