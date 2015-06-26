# Created by: KalleDK <plexmaintainer@k-moeller.dk>
# $FreeBSD$

PORTNAME=	plexmediaserver
PORTVERSION?=	0.9.12.4.1192
PORTREVISION?=	0
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.plexapp.com/plex-media-server/${PORTVERSION}-${PLEX_BUILD}/ \
		http://nightlies.plexapp.com/directdl/plex-media-server/dist-ninja/${PORTVERSION}-${PLEX_BUILD}/
DISTNAME=	PlexMediaServer-${PORTVERSION}-${PLEX_BUILD}-freebsd-${ARCH}

MAINTAINER?=	feld@FreeBSD.org
COMMENT=	Plex Media Server component

USES=	tar:bzip2
PLEX_BUILD?=	9a47d21
NO_BUILD=	yes
WRKSRC=	${WRKDIR}/PlexMediaServer-${PORTVERSION}-${PLEX_BUILD}

USE_RC_SUBR?=	${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST?=	PORTNAME=${PORTNAME} DATADIR=${DATADIR} USERS=${USERS} GROUPS=${GROUPS}

USERS=	plex
GROUPS=	${USERS}
BUNDLE_LIBS=	yes

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	binary-only program, source code not available

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
	${FIND} ${WRKSRC}/Resources -name '*.so' -exec ${STRIP_CMD} {} \;
	${STRIP_CMD} ${WRKSRC}/Resources/rsync ${WRKSRC}/Resources/Python/bin/python

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} Resources ${STAGEDIR}/${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/Plex\ DLNA\ Server ${STAGEDIR}/${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/Plex\ Media\ Scanner ${STAGEDIR}/${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/Plex\ Media\ Server ${STAGEDIR}/${DATADIR}
	${INSTALL_LIB} ${WRKSRC}/lib* ${STAGEDIR}/${DATADIR}
	# Fix permissions to programs and db
	@${CHMOD} a+x ${STAGEDIR}/${DATADIR}/Resources/rsync
	@${CHMOD} a+x ${STAGEDIR}/${DATADIR}/Resources/Plex\ New\ Transcoder
	@${CHMOD} a+x ${STAGEDIR}/${DATADIR}/Resources/Plex\ Transcoder
	@${CHMOD} a+x ${STAGEDIR}/${DATADIR}/Resources/Python/bin/python
	@${CHMOD} u+w ${STAGEDIR}/${DATADIR}/Resources/com.plexapp.plugins.library.db
	# Python fix
	@${LN} -s ${DATADIR}/libpython2.7.so.1 ${STAGEDIR}/${DATADIR}/libpython2.7.so
	# Workaround for space in binary name
	@${LN} -s ${DATADIR}/Plex\ Media\ Server ${STAGEDIR}${DATADIR}/Plex_Media_Server

.include <bsd.port.post.mk>
