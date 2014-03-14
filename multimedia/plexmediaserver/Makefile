# Created by: KalleDK <plexmaintainer@k-moeller.dk>
# $FreeBSD$

PORTNAME=	plexmediaserver
PORTVERSION=	0.9.9.7.429
CATEGORIES=	multimedia
MASTER_SITES=	http://plex.r.worldssl.net/plex-media-server/${PORTVERSION}-${PLEX_BUILD}/
DISTNAME=	PlexMediaServer-${PORTVERSION}-${PLEX_BUILD}-freebsd-amd64

MAINTAINER=	feld@FreeBSD.org
COMMENT=	The Plex Media Server component

USE_BZIP2=	yes
PLEX_BUILD=	f80a8d6
NO_BUILD=	yes
WRKSRC=	${WRKDIR}/PlexMediaServer-${PORTVERSION}-${PLEX_BUILD}

USE_RC_SUBR=	plexmediaserver

SUB_FILES=	plexmediaserver
SUB_LIST=	SUPPORT_PATH=${SUPPORT_PATH} SCRIPT_PATH="${SCRIPT_PATH}" USERS=${USERS} GROUPS=${GROUPS}

USERS=	plex
GROUPS=	plex
SUPPORT_PATH?=	${PREFIX}/plexdata
SCRIPT_PATH?=	${DATADIR}

ONLY_FOR_ARCHS=	amd64

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
.if ${OSVERSION} < 900000
IGNORE=	supplied binaries compiled for FreeBSD 9
.endif

.if ${OSVERSION} >= 1000054
RUN_DEPENDS+=	${LOCALBASE}/lib/compat/libstdc++.so.6:${PORTSDIR}/misc/compat9x
.endif
.endif

post-patch:
	# binaries don't come pre-stripped
	${FIND} ${WRKSRC} -name '*.so' -exec ${STRIP_CMD} {} \;

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} Resources ${STAGEDIR}/${SCRIPT_PATH})
	${INSTALL_PROGRAM} ${WRKSRC}/Plex\ DLNA\ Server ${STAGEDIR}/${SCRIPT_PATH}
	${INSTALL_PROGRAM} ${WRKSRC}/Plex\ Media\ Scanner ${STAGEDIR}/${SCRIPT_PATH}
	${INSTALL_PROGRAM} ${WRKSRC}/Plex\ Media\ Server ${STAGEDIR}/${SCRIPT_PATH}
	${INSTALL_SCRIPT} ${WRKSRC}/start.sh ${STAGEDIR}/${SCRIPT_PATH}
	${INSTALL_LIB} ${WRKSRC}/lib* ${STAGEDIR}/${SCRIPT_PATH}
	# Fix permissions to programs and db
	@${CHMOD} a+x ${STAGEDIR}/${SCRIPT_PATH}/Resources/rsync
	@${CHMOD} a+x ${STAGEDIR}/${SCRIPT_PATH}/Resources/Plex\ New\ Transcoder
	@${CHMOD} a+x ${STAGEDIR}/${SCRIPT_PATH}/Resources/Plex\ Transcoder
	@${CHMOD} a+x ${STAGEDIR}/${SCRIPT_PATH}/Resources/Python/bin/python
	@${CHMOD} u+w ${STAGEDIR}/${SCRIPT_PATH}/Resources/com.plexapp.plugins.library.db
	# Python fix
	@${LN} -s ${SCRIPT_PATH}/libpython2.7.so.1 ${STAGEDIR}/${SCRIPT_PATH}/libpython2.7.so

.include <bsd.port.post.mk>
