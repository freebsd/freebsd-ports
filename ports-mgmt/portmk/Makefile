# New ports collection makefile for:	portmk
# Date created:				05 Jul 2004
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=	portmk
PORTVERSION=	0.1.1
CATEGORIES=	devel
DISTFILES=

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Development version of bsd.port.mk

PKGMESSAGE=	${WRKDIR}/pkg-message

NO_BUILD=	yes
PLIST_FILES=	bin/omake

PORTDOCS=	ReadMe ChangeLog Features KnownIssues

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
PORTMK_PATCH=	${FILESDIR}/portmk4.patch
.else
PORTMK_PATCH=	${FILESDIR}/portmk5.patch
.endif

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
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${FILESDIR}/${doc} ${DOCSDIR}
.endfor
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

.include <bsd.port.post.mk>
