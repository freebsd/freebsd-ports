# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	spambnc
PORTVERSION=	20060416
CATEGORIES=	mail
MASTER_SITES=	http://www.spambouncer.org/dist/sb/:tarball	\
		http://www.spambouncer.org/configure/:doc
DISTFILES=	sb.tar.gz:tarball	quickstart.shtml:doc
DIST_SUBDIR=	spambnc-${PORTVERSION}
EXTRACT_ONLY=	sb.tar.gz

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Set of procmail recipes which handle known/suspected spam

LICENSE=	GPLv2

RUN_DEPENDS=	procmail:${PORTSDIR}/mail/procmail

IGNOREFILES=	quickstart.shtml
EXTRACT_DIR=	${WRKDIRPREFIX}${.CURDIR}/worktmp/${DISTNAME}
EXTRACT_BEFORE_ARGS=	-C ${EXTRACT_DIR} -xf
NO_BUILD=	yes
NO_ARCH=	yes
PLIST=		${WRKDIR}/.pkg-plist
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

.if !defined(NOPORTDOCS)
MASTER_SITES+=	http://www.spambouncer.org/configure/:upg
DISTFILES+=	upgrading.shtml:upg
IGNOREFILES+=	upgrading.shtml
PORTDOCS=	documentation.html upgrading.html loglevels.txt
.endif

pre-extract:
	${MKDIR} ${EXTRACT_DIR}

post-extract:
	${MV} ${EXTRACT_DIR} ${WRKDIR}
	${RM} -rf ${WRKDIRPREFIX}${.CURDIR}/worktmp

pre-install:
	(cd ${WRKSRC} && ${FIND} -s . -type f | ${GREP} -v "^\.\/\." |	\
		${GREP} -v docs | ${SED} -e 's,.,%%DATADIR%%,1' > ${PLIST})
	(cd ${WRKSRC} && ${FIND} -s . -type d | ${GREP} -v docs | ${SORT} -r |	\
		${SED} -e 's,.,@dirrm %%DATADIR%%,' >> ${PLIST})

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	${RM} -rf ${STAGEDIR}${DATADIR}/docs
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/quickstart.shtml \
		${STAGEDIR}${DOCSDIR}/documentation.html
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/upgrading.shtml \
		${STAGEDIR}${DOCSDIR}/upgrading.html
	${INSTALL_DATA} ${WRKSRC}/docs/loglevels.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
