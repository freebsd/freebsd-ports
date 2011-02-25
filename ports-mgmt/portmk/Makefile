# New ports collection makefile for:	portmk
# Date created:				05 Jul 2004
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=	portmk
PORTVERSION=	0.1.1
CATEGORIES=	ports-mgmt
DISTFILES=

MAINTAINER=	portmgr@FreeBSD.org
COMMENT=	Development version of bsd.port.mk

DEPRECATED=		has not been kept up to date for > 6 months
EXPIRATION_DATE=	2011-04-24

PKGMESSAGE=	${WRKDIR}/pkg-message

NO_BUILD=	yes
PLIST_FILES=	bin/omake

PORTDOCS=	ReadMe ChangeLog Features KnownIssues

MASTER_SITE_PATCHOMATIC?=	http://people.freebsd.org/~clement/portmk/
PATCHOMATIC_FILE?=		patch-o-matic-latest.tar.bz2
WRKSRC=				${WRKDIR}/patch-o-matic

.include <bsd.port.pre.mk>

PORTMK_PATCH=	${FILESDIR}/portmk5.patch

post-patch:
.for text in pkg-message
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%PORTSDIR%%,${PORTSDIR},g' \
		-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		${PKGDIR}/${text} >${WRKDIR}/${text}
.endfor

do-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/omake.sh ${PREFIX}/bin/omake

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${FILESDIR}/${doc} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

activate:
	@if [ "`${ECHO_CMD} FreeBSD | ${TR} -s .`" != "FreeBSD" ]; then \
		${ECHO_MSG} "tr(1) is broken."; \
		${FALSE}; \
	fi
	@${GREP} -qs PORTMK /usr/share/mk/bsd.port.mk || \
		${PATCH} -s -N -d /usr/share/mk -i ${PORTMK_PATCH} && \
		${ECHO_MSG} ">> Configured bsd.port.mk."
	@${GREP} -qs PORTMK /etc/make.conf || \
		${CAT} ${FILESDIR}/make.conf >> /etc/make.conf && \
		${ECHO_MSG} ">> Configured make.conf(5)."

patch-o-matic:
	@${MKDIR} ${WRKDIR}
	@${ECHO_CMD} "==> Fetching patch-o-matic file (${MASTER_SITE_PATCHOMATIC}/${PATCHOMATIC_FILE}"
	@(cd ${WRKDIR} ; ${RM} -f ${PATCHOMATIC_FILE} ; ${FETCH_CMD} \
		${MASTER_SITE_PATCHOMATIC}/${PATCHOMATIC_FILE})
	@${TAR} yxf ${WRKDIR}/${PATCHOMATIC_FILE} -C ${WRKDIR}
	@${ECHO_CMD} "==> Applying patches..."
	@for patch in $$(${CAT} ${WRKSRC}/AFFECTED_PORTS); do \
		eval `${ECHO_CMD} $$patch | ${AWK} -F\: \
			'{print "PORT="$$1"; PATCH="$$2";"}'`; \
		[ -e ${WRKSRC}/patches/$$PATCH ] && { \
		${ECHO_CMD} -n " Applying $$PATCH to $$PORT... " ; \
		${PATCH} -d ${PORTSDIR} -p0 < ${WRKSRC}/patches/$$PATCH > /dev/null 2>&1 || echo -n "N" ;\
		echo OK ;\
		}; ${TRUE} ;\
	done

.include <bsd.port.post.mk>
