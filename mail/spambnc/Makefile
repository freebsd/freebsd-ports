# New ports collection makefile for:   spambnc
# Date created:        25 December 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	spambnc
PORTVERSION=	20050516
CATEGORIES=	mail
MASTER_SITES=	http://www.spambouncer.org/	\
		ftp://ftp.spambouncer.org/
DISTFILES=	sb-beta.tar.gz index.shtml
DIST_SUBDIR=	spambnc-${PORTVERSION}
EXTRACT_ONLY=	sb-beta.tar.gz

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Set of procmail recipies which handle known/suspected spam

RUN_DEPENDS=	procmail:${PORTSDIR}/mail/procmail

IGNOREFILES=	index.shtml
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST=		${WRKDIR}/.pkg-plist
PKGMESSAGE=	${WRKDIR}/pkg-message

SUB_DIRS=	functions docs data auxiliary

.if !defined(NOPORTDOCS)
MASTER_SITES+=	http://www.spambouncer.org/webdev/configure/:upg
DISTFILES+=	upgrading.shtml:upg
IGNOREFILES+=	upgrading.shtml
.endif

pre-install:
	@${RM} -f ${PLIST}
	@(cd ${WRKDIR} && ${FIND} -s . -type f | ${GREP} -v "^\.\/\." | \
		${SED} -e 's,.,%%DATADIR%%,1' >> ${PLIST})
.for dd in ${SUB_DIRS}
	@${ECHO_CMD} "@dirrm %%DATADIR%%/${dd}" >> ${PLIST}
.endfor
	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} "%%DOCSDIR%%/documentation.html" >> ${PLIST}
	@${ECHO_CMD} "%%DOCSDIR%%/upgrading.html" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DOCSDIR%%" >> ${PLIST}
.endif

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKDIR} && ${CP} -Rv * ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/index.shtml \
		${DOCSDIR}/documentation.html
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/upgrading.shtml \
		${DOCSDIR}/upgrading.html
.endif

post-install:
	@${SED} -e 's,%%DOCSDIR%%,${DOCSDIR},;s,%%DATADIR%%,${DATADIR},' \
		< ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
