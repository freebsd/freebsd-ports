# Created by: Matt Emmerton <matt@gsicomp.on.ca>
# $FreeBSD$

PORTNAME=	vlogin
PORTVERSION=	3.10.2
PORTREVISION=	1
CATEGORIES=	mail www
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.2.7

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adds multi-site-hosting capabilities to SquirrelMail

USE_SM_COMPAT=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

# We need to rearrange, install and cleanup documentation pre-install
# because bsd.squirrelmail.mk installs everything under ${WRKSRC}/${PORTNAME}.
pre-install::
	cd ${WRKSRC}/${PORTNAME}/docs \
	&& ${RM} .htaccess index.php \
	&& ${MKDIR} ${STAGEDIR}${DOCSDIR} \
	&& ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR} \
	&& cd ${WRKSRC}/${PORTNAME} \
	&& ${RM} -rf README docs

.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.mk>
