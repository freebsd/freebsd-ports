# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	genpatch
PORTVERSION=	1.40
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Single patch generator tool compatible with makepatch format

LICENSE=	BSD2CLAUSE

NO_BUILD=	yes
SUB_FILES=	genpatch portfix
SUB_LIST=	WORKPATH=${PORTWORK}
PLIST_FILES=	bin/dupe \
		bin/genpatch \
		bin/portfix \
		man/man1/dupe.1.gz \
		man/man1/genpatch.1.gz \
		man/man1/portfix.1.gz

.include <bsd.port.options.mk>

.if defined(PACKAGE_BUILDING) # use known default values, poudriere overrides
.  if defined(.MAKE.BUILT.BY) # DragonFly!
PORTWORK=	/usr/obj/dports
.  else
PORTWORK=	/usr/ports
.  endif
.else
.  if defined(WRKDIRPREFIX) && !empty(WRKDIRPREFIX)
PORTWORK=	${WRKDIRPREFIX}
.  else
PORTWORK=	${PORTSDIR}
.  endif
.endif

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/dupe   ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/genpatch ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/portfix  ${STAGEDIR}${PREFIX}/bin
	(cd ${FILESDIR} && ${INSTALL_MAN} dupe.1 genpatch.1 portfix.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)

.include <bsd.port.mk>
