PORTNAME=	susv2
PORTVERSION=	1.0.20010716
CATEGORIES=	misc
MASTER_SITES=	#
DISTNAME=	susv2

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Single UNIX Specification Version 2
WWW=		http://www.unix.org/version2/online.html

# Redistribution of the documents is not permitted
LICENSE=	NONE

USES=		tar:bzip2

NO_ARCH=	yes
NO_BUILD=	yes
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
# Fix fallout of https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=230864 and force the option on;
# meaning is to force this option on. The previous change around Sept 2018 introduced a regression in
# that PORTDOCS only works if there is a DOCS option.  It does not, however, make sense to install
# empty documentation ports.
OPTIONS_SLAVE=	DOCS

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		may not be redistributed because of licensing reasons. Please visit http://www.unix.org/version2/online.html or http://pubs.opengroup.org/onlinepubs/7908799/download/ to accept their license and download ${DISTFILES} into ${DISTDIR}
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} '*' ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
