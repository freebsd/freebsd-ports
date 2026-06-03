PORTNAME=	susv4
PORTVERSION=	20220408
CATEGORIES=	misc
MASTER_SITES=	#
DISTNAME=	susv4-2018
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Open Group Base Specifications Issue 7/IEEE Std 1003.1, 2018 Edition
WWW=		http://www.unix.org/online.html

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

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		may not be redistributed because of licensing reasons. Please visit http://www.unix.org/online.html to accept their license and download ${DISTFILES} into ${DISTDIR}/${DIST_SUBDIR}
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${FIND} . -name '*~' -delete && \
		${COPYTREE_SHARE} '*' ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
