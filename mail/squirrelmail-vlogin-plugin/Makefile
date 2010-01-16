# New ports collection makefile for:	squirrelmail-vlogin-plugin
# Date created:		10 Oct 2005
# Whom:		Matt Emmerton <matt@gsicomp.on.ca>
#
# $FreeBSD$

PORTNAME=	vlogin
PORTVERSION=	3.10.2
CATEGORIES=	mail www
MASTER_SITES=	http://www.squirrelmail.org/plugins/
PKGNAMEPREFIX=	squirrelmail-
PKGNAMESUFFIX=	-plugin
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.2.7
DIST_SUBDIR=	squirrelmail

MAINTAINER=	neil@darlow.co.uk
COMMENT=	Adds multi-site-hosting capabilities to SquirrelMail

USE_PERL5_RUN=	yes
USE_SM_COMPAT=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/mail/squirrelmail/bsd.squirrelmail.mk"

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

.include <bsd.port.post.mk>
