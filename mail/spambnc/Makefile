# New ports collection makefile for:   spambnc
# Date created:        25 December 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

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

RUN_DEPENDS=	procmail:${PORTSDIR}/mail/procmail

IGNOREFILES=	quickstart.shtml
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST=		${WRKDIR}/.pkg-plist
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

.if !defined(NOPORTDOCS)
MASTER_SITES+=	http://www.spambouncer.org/configure/:upg
DISTFILES+=	upgrading.shtml:upg
IGNOREFILES+=	upgrading.shtml
PORTDOCS=	documentation.html upgrading.html loglevels.txt
.endif

pre-install:
	@(cd ${WRKSRC} && ${FIND} -s . -type f | ${GREP} -v "^\.\/\." |	\
		${GREP} -v docs | ${SED} -e 's,.,%%DATADIR%%,1' > ${PLIST})
	@(cd ${WRKSRC} && ${FIND} -s . -type d | ${GREP} -v docs | ${SORT} -r |	\
		${SED} -e 's,.,@dirrm %%DATADIR%%,' >> ${PLIST})

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${CP} -Rv * ${DATADIR}
	@${RM} -rf ${DATADIR}/docs
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/quickstart.shtml \
		${DOCSDIR}/documentation.html
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/upgrading.shtml \
		${DOCSDIR}/upgrading.html
	@${INSTALL_DATA} ${WRKSRC}/docs/loglevels.txt ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
