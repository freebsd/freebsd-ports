# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=		sasql
PORTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	http://www.squirrelmail.org/plugins/
PKGNAMEPREFIX=	squirrelmail-
PKGNAMESUFFIX=	-plugin
DIST_SUBDIR=	squirrelmail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Edit SpamAssassin settings stored in an SQL DB

RUN_DEPENDS=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB

USES=		perl5
USE_PERL5=	install
USE_SM_COMPAT=	yes

NO_STAGE=	yes

post-patch:
	@${RM} ${WRKSRC}/${SQUIRREL_PLUGIN_NAME}/*.orig ${WRKSRC}/${SQUIRREL_PLUGIN_NAME}/.cvsignore

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.post.mk>
