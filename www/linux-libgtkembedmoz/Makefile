# Created by: hrs
# $FreeBSD$

PORTNAME=	libgtkembedmoz
PORTVERSION=	0.0.20100806
CATEGORIES=	www
MASTER_SITES=	http://cvs.nvu.com/download/
PKGNAMEPREFIX=	linux-
DISTNAME=	nvu-1.0-pc-linux2.6.10-gnu

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	HTML rendering library

BROKEN=		No public distfiles

NO_BUILD=	yes
ONLY_FOR_ARCHS=	amd64 i386
USES=		uidfix tar:bzip2
USE_LINUX=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/nvu-1.0
PLIST_SUB=	MOZLIBDIR=${MOZLIBDIR}

MOZLIBDIR=	lib/${PKGNAMEPREFIX}${PORTNAME}

do-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}
	${MKDIR} ${STAGEDIR}${PREFIX}/${MOZLIBDIR}
	(cd ${WRKSRC} && ${TAR} -cpf - --exclude "res/samples/" \
		--exclude "res/sample*" lib* res components) | \
		( cd ${STAGEDIR}${PREFIX}/${MOZLIBDIR} && ${TAR} xpf - )

.include <bsd.port.mk>
