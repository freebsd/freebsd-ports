# Created by: hrs
# $FreeBSD$

PORTNAME=	libgtkembedmoz
PORTVERSION=	0.0.20100806
CATEGORIES=	www
MASTER_SITES=	http://cvs.nvu.com/download/ CSME
PKGNAMEPREFIX=	linux-
DISTNAME=	nvu-1.0-pc-linux2.6.10-gnu

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	HTML rendering library

NO_BUILD=	yes
ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/nvu-1.0
PLIST_SUB=	MOZLIBDIR=${MOZLIBDIR}

MOZLIBDIR=	lib/${PKGNAMEPREFIX}${PORTNAME}

NO_STAGE=	yes
do-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}
	${MKDIR} ${PREFIX}/${MOZLIBDIR}
	(cd ${WRKSRC} && ${TAR} -cpf - --exclude "res/samples/" \
		--exclude "res/sample*" lib* res components) | \
		( cd ${PREFIX}/${MOZLIBDIR} && ${TAR} xpf - )

.include <bsd.port.mk>
