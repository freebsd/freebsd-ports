# New ports collection makefile for:   lingoteach
# Date created:        01 September 2002
# Whom:                Marcus vA
#
# $FreeBSD$
#

PORTNAME=	lingoteach
PORTVERSION=	0.3.8
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
.if defined(WITH_SOUND)
DISTFILES=	${PORTNAME}-sound-${PORTVERSION}.tar.gz \
		${PORTNAME}-${PORTVERSION}.tar.gz
.endif

MAINTAINER=	mva@sysfault.org
COMMENT=	A language teaching program with sound

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

.if defined(WITH_SOUND)
RUN_DEPENDS=	ogg123:${PORTSDIR}/audio/vorbis-tools
.endif

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	""
USE_GMAKE=	yes

.if defined(WITH_COMP)
CONFIGURE_ARGS+=	--with-compression
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_SOUND)
PLIST=		${WRKDIR}/plist
.endif

SORT?=		/usr/bin/sort

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "	Available options for lingoteach:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} " 		 WITH_SOUND	download additional sounds"
	@${ECHO_CMD} "				for lingoteach"
	@${ECHO_CMD} "		 WITH_COMP	enable compression of data"
	@${ECHO_CMD} "				files"
	@${ECHO_CMD} " 		 WITH_DEBUG	enable debugging"
	@${ECHO_CMD} ""

.if defined(WITH_SOUND)
pre-install::
	${CAT} pkg-plist | ${SED} '/@dirrm/d' > ${WRKDIR}/plist; \
	cd ${WRKDIR}/${PORTNAME}-sound-${PORTVERSION}/data; \
	${FIND} . -type f \! -name "Make*" | cut -c2- | \
	${SED} 's|^|${DATADIR:S,${PREFIX}/,,}/data|' \
	| ${SORT} >> ${PLIST}; \
	${CAT} ${WRKDIR}/../pkg-plist | ${GREP} '@dirrm include' >> ${PLIST}; \
	cd ${WRKDIR}/${PORTNAME}-sound-${PORTVERSION}/data; \
	${FIND} . -type d | cut -c2- | ${SED} \
	's|^|@dirrm ${DATADIR:S,${PREFIX}/,,}/data|' | ${SORT} -r >> ${PLIST};
	${ECHO_CMD} "@dirrm ${DATADIR:S,${PREFIX}/,,}" >> ${PLIST};
.endif

.if defined(WITH_SOUND)
post-install::
	cd ${WRKDIR}/${PORTNAME}-sound-${PORTVERSION}/data; \
	${RM} -f Make*; \
	${CP} -R ${WRKDIR}/${PORTNAME}-sound-${PORTVERSION}/data \
	${DATADIR};
.endif

.include <bsd.port.post.mk>
