# New ports collection makefile for:   spambnc
# Date created:        25 December 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	spambnc
PORTVERSION=	20021213
CATEGORIES=	mail
MASTER_SITES=	http://www.spambouncer.org/
DISTFILES=	sb.tar.Z index.shtml
DIST_SUBDIR=	spambnc-${PORTVERSION}
EXTRACT_ONLY=	sb.tar.Z

MAINTAINER=	greid@FreeBSD.org

IGNOREFILES=	index.shtml
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST=		${WRKDIR}/.pkg-plist

pre-install:
	@${RM} -f ${PLIST}
	@(cd ${WRKDIR} && find -s . -type f | ${GREP} -v "^\.\/\." | \
		${SED} -e 's,.,share/spambnc,1' >> ${PLIST})
	@echo "%%PORTDOCS%%share/doc/spambnc/documentation.html" >> ${PLIST}
	@echo "@dirrm share/spambnc" >> ${PLIST}
	@echo "%%PORTDOCS%%@dirrm share/doc/spambnc" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/share/spambnc/
	cd ${WRKDIR} && ${CP} -Rv * ${PREFIX}/share/spambnc
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/spambnc/
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/index.shtml \
		${PREFIX}/share/doc/spambnc/documentation.html
.endif

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
