# Created by: Matt Emmerton <matt@gsicomp.on.ca>
# $FreeBSD$

PORTNAME=	vlogin
PORTVERSION=	3.10.2
PORTREVISION=	1
CATEGORIES=		mail www
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.2.7

MAINTAINER=	neil@darlow.co.uk
COMMENT=	Adds multi-site-hosting capabilities to SquirrelMail

USE_SM_COMPAT=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"

# We need to rearrange, install and cleanup documentation pre-install
# because bsd.squirrelmail.mk installs everything under ${WRKSRC}/${PORTNAME}.
pre-install::
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/${PORTNAME}/docs \
	&& ${RM} .htaccess index.php \
	&& ${MKDIR} ${DOCSDIR} \
	&& ${COPYTREE_SHARE} \* ${DOCSDIR} \
	&& cd ${WRKSRC}/${PORTNAME} \
	&& ${RM} -rf README docs
.else
	cd ${WRKSRC}/${PORTNAME} && ${RM} -rf README docs
.endif

.include <bsd.port.mk>
