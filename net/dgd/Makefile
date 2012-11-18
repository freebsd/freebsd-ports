# New ports collection makefile for:	dgd
# Date created:		23 August 1994
# Whom:			adam@veda.is
#
# $FreeBSD$
#

PORTNAME=	dgd
PORTVERSION=	1.4.18
CATEGORIES=	net lang games
MASTER_SITES=	http://cloud.github.com/downloads/dworkin/${PORTNAME}/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Dworkin\'s Game Driver

LICENSE=	GPLv3

OPTIONS=	NETWORKING	"With networking kfuns"		off \
		CLOSURES	"With function pointer support"	off \
		CPLUSPLUS_COMMENTS	"With C++ style comment support"	on

USE_GMAKE=	yes

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}/dgd/src
PATCH_WRKSRC=	${WRKDIR}/dgd
ALL_TARGET=	install
MAKE_JOBS_UNSAFE=	yes
MAKE_ENV+=	EXTRA_DEFINES="$(EXTRA_DEFINES)"

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

USERS=		mud
GROUPS=		mud

.include <bsd.port.pre.mk>

EXTRA_DEFINES=

.if defined(WITH_CLOSURES)
EXTRA_DEFINES+=	-DCLOSURES
.endif

.if defined(WITH_CPLUSPLUS_COMMENTS)
EXTRA_DEFINES+=	-DSLASHSLASH
.endif

.if defined(WITH_NETWORKING)
EXTRA_DEFINES+=	-DNETWORK_EXTENSIONS
.endif

post-patch:
	@cd ${WRKDIR}/dgd/ && ${FIND} . -name '*.orig' -delete

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/dgd/bin/driver ${PREFIX}/sbin/dgd
	${INSTALL_PROGRAM} ${WRKDIR}/dgd/bin/precomp ${PREFIX}/bin/precomp
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/dgd/mud.dgd \
		${PREFIX}/etc/${PORTNAME}/mud.dgd.sample
	@# Install an RC script for DGD
	${CAT} ${FILESDIR}/dgd.sh | ${SED} -e "s:%%PREFIX%%:${PREFIX}:" \
		-e "s:%%DATADIR%%:${DATADIR}:" > \
			${PREFIX}/etc/rc.d/dgd.sh.sample
	${CHMOD} a+x ${PREFIX}/etc/rc.d/dgd.sh.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/dgd/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/dgd/README ${DOCSDIR}
	cd ${WRKDIR}/dgd/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
