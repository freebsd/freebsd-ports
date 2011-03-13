# Ports collection makefile for:	graft
# Date created:				2004-08-15
# Whom:					Michael Handler <handler@grendel.net>
#
# $FreeBSD$
#

PORTNAME=		graft
PORTVERSION=		2.4
CATEGORIES=		sysutils
MASTER_SITES=		http://www.gormand.com.au/peters/tools/graft/

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Automatically manage symlinks in a directory hierarchy

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_PERL5=		yes

PLIST_FILES=		bin/graft

INSTALL_TARGET=		bin manuals
MAN1=			graft.1

.if !defined(NOPORTDOCS)
EXTRAPORTDOCS=		CHANGES README THOUGHTS
PORTDOCS=		graft.html graft.pdf graft.ps graft.txt ${EXTRAPORTDOCS}
INSTALL_TARGET+=	docs
.endif

GRAFT_PACKAGEDIR?=	/local/pkg
GRAFT_TARGETDIR?=	/local
GRAFT_LOGFILE?=		/var/log/graft

MAKEFILE_SUB=		PREFIX=${PREFIX} MANPREFIX=${MANPREFIX} \
			DOCSDIR=${DOCSDIR} PERL=${PERL} \
			GRAFT_PACKAGEDIR=${GRAFT_PACKAGEDIR} \
			GRAFT_TARGETDIR=${GRAFT_TARGETDIR} \
			GRAFT_LOGFILE=${GRAFT_LOGFILE}

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} "You may use the following build options:"
	@${ECHO_CMD}
	@${ECHO_CMD} "GRAFT_PACKAGEDIR=/directory (default: ${GRAFT_PACKAGEDIR})"
	@${ECHO_CMD} "GRAFT_TARGETDIR=/directory (default: ${GRAFT_TARGETDIR})"
	@${ECHO_CMD} "GRAFT_LOGFILE=/directory/file (default: ${GRAFT_LOGFILE})"
	@${ECHO_CMD}

post-patch:
	@${SED} ${MAKEFILE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/Makefile.dist > ${WRKSRC}/Makefile

.if !defined(NOPORTDOCS)
post-install:
.for i in ${EXTRAPORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
