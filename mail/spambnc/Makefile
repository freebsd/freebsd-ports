# New ports collection makefile for:   spambnc
# Date created:        25 December 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	spambnc
PORTVERSION=	20040731
CATEGORIES=	mail
MASTER_SITES=	http://www.spambouncer.org/	\
		ftp://ftp.spambouncer.org/
DISTFILES=	sb.tar.gz index.shtml
DIST_SUBDIR=	spambnc-${PORTVERSION}
EXTRACT_ONLY=	sb.tar.gz

MAINTAINER=	thierry@pompo.net
COMMENT=	Set of procmail recipies which handle known/suspected spam

RUN_DEPENDS=	procmail:${PORTSDIR}/mail/procmail

IGNOREFILES=	index.shtml
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST=		${WRKDIR}/.pkg-plist

pre-install:
	@${RM} -f ${PLIST}
	@(cd ${WRKDIR} && ${FIND} -s . -type f | ${GREP} -v "^\.\/\." | \
		${SED} -e 's,.,%%DATADIR%%,1' >> ${PLIST})
	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} "%%DOCSDIR%%/documentation.html" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DOCSDIR%%" >> ${PLIST}
.endif

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKDIR} && ${CP} -Rv * ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/index.shtml \
		${DOCSDIR}/documentation.html
.endif

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
