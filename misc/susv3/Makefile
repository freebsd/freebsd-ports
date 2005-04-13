# New ports collection makefile for:	susv3
# Date created:		11 April 2002
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	susv3
PORTVERSION=	1.1
CATEGORIES=	misc
MASTER_SITES=	#
DISTNAME=	susv3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Single UNIX Specification Version 3

RESTRICTED=	"Redistribution of the documents is not permitted"

USE_BZIP2=	yes
NO_BUILD=	yes

PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		"may not be redistributed because of licensing reasons. Please visit http://www.unix-systems.org/version3/online.html to accept their license and download ${DISTFILES} into ${DISTDIR}"
.endif

do-install:
	@${MKDIR} ${DOCSDIR}
	@> ${PLIST}
	@${FIND} ${WRKSRC} | ${SED} -e 's#^${WRKSRC}##' | while read file; do \
		if ${TEST} -d "${WRKSRC}$$file"; then \
			${MKDIR} "${DOCSDIR}$$file"; \
			${ECHO} "@dirrm ${DOCSDIR:S#^${PREFIX}/##}$$file" >> ${PLIST}; \
		else \
			if ${TEST} -L "${WRKSRC}$$file"; then \
				${LN} -s "`${LS} -l \"${WRKSRC}$$file\" | ${SED} -e 's/^.*> //'`" \
					"${DOCSDIR}$$file"; \
			else \
				${INSTALL_DATA} "${WRKSRC}$$file" "${DOCSDIR}$$file"; \
			fi; \
			${ECHO} "${DOCSDIR:S#^${PREFIX}/##}$$file" >> ${PLIST}; \
		fi; \
	done
	@(${RM} -f ${PLIST}; ${SED} -ne '/^@/{G;h;};/^@/!p;$${g;p;}' > ${PLIST}) < ${PLIST}

.include <bsd.port.post.mk>
