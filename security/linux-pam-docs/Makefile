# New ports collection makefile for: Linux-PAM offline documentation
# Date created:		19 Jun 2003
# Whom:			Hideyuki KURASHINA <rushani@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linux-pam-docs
PORTVERSION=	0.76
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_KERNEL_ORG}
MASTER_SITE_SUBDIR=	linux/libs/pam/pre/history
DISTNAME=	Linux-PAM-${PORTVERSION}-docs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux-PAM offline documentation

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
CPIO=		cpio --quiet -pdum -R

do-install:
	@ ${MKDIR} ${DOCSDIR}
	@ cd ${WRKSRC} && ${FIND} * \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}

.include <bsd.port.mk>
