# Created by: Hideyuki KURASHINA <rushani@FreeBSD.org>
# $FreeBSD$

PORTNAME=	linux-pam-docs
PORTVERSION=	1.1.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_KERNEL_ORG}
MASTER_SITE_SUBDIR=	linux/libs/pam/documentation/
DISTNAME=	Linux-PAM-${PORTVERSION}-docs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux-PAM offline documentation

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

BROKEN=		distfile mismatch

WRKSRC=		${WRKDIR}/Linux-PAM-${PORTVERSION}
NO_BUILD=	yes

.if defined(NOPORTDOCS)
IGNORE=		can't be installed when NOPORTDOCS is defined
.endif

NO_STAGE=	yes
do-install:
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${DOCSDIR})

.include <bsd.port.mk>
