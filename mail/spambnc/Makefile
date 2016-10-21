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

RUN_DEPENDS=	procmail:mail/procmail

EXTRACT_DIR=	${WRKDIRPREFIX}${.CURDIR}/worktmp/${DISTNAME}
EXTRACT_BEFORE_ARGS=	-C ${EXTRACT_DIR} -xf
NO_BUILD=	yes
NO_ARCH=	yes
PLIST=		${WRKDIR}/.pkg-plist
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

PORTDATA=	*
PORTDOCS=	documentation.html upgrading.html loglevels.txt

OPTIONS_DEFINE=	DOCS

DOCS_MASTER_SITES=	http://www.spambouncer.org/configure/:upg
DOCS_DISTFILES=		upgrading.shtml:upg

pre-extract:
	${MKDIR} ${EXTRACT_DIR}

post-extract:
	${MV} ${EXTRACT_DIR} ${WRKDIR}
	${RM} -r ${WRKDIRPREFIX}${.CURDIR}/worktmp

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	${RM} -r ${STAGEDIR}${DATADIR}/docs

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/quickstart.shtml \
		${STAGEDIR}${DOCSDIR}/documentation.html
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/upgrading.shtml \
		${STAGEDIR}${DOCSDIR}/upgrading.html
	${INSTALL_DATA} ${WRKSRC}/docs/loglevels.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
