# New ports collection makefile for:   lingoteach
# Date created:        01 September 2002
# Whom:                Marcus vA
#
# $FreeBSD$
#

PORTNAME=	lingoteach
PORTVERSION=	0.3.7
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
.if defined(WITH_SOUND)
DISTFILES=	${PORTNAME}-sound-${PORTVERSION}.tar.gz \
		${PORTNAME}-${PORTVERSION}.tar.gz
.endif

MAINTAINER=	mva121@gmx.net

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20
.if defined(WITH_SOUND)
RUN_DEPENDS=	ogg123:${PORTSDIR}/audio/vorbis-tools
.endif

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	""
USE_GMAKE=	yes

.if defined(WITH_SOUND)
PLIST=		${WRKDIR}/plist
.endif

SORT?=		/usr/bin/sort

.include <bsd.port.pre.mk>

.if !defined(WITH_SOUND)
pre-extract::
	@${ECHO_CMD} "************************************************"
	@${ECHO_CMD} "*                                              *"
	@${ECHO_CMD} "* For Sound in Lingoteach, type Ctrl-C now and *"
	@${ECHO_CMD} "*            define WITH_SOUND=yes             *"
	@${ECHO_CMD} "*                                              *"
	@${ECHO_CMD} "************************************************"
	@sleep 3
.endif

.if defined(WITH_SOUND)
pre-install::
	cd ${WRKSRC}/src; ${ECHO_CMD} \
	"bin/`find . -type f -perm 755 |cut -c3-`" > ${PLIST}; \
	cd ${WRKDIR}/${PORTNAME}-sound-${PORTVERSION}/data; \
	${FIND} . -type f \! -name "Make*" | cut -c2- | \
	${SED} 's|^|${DATADIR:S,${PREFIX}/,,}/data|' \
	| ${SORT} >> ${PLIST}; \
	cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/data; \
	${FIND} . -type f \! -name "Make*" | cut -c2- | ${SED} \
	's|^|${DATADIR:S,${PREFIX}/,,}/data|' | ${SORT} >> ${PLIST}; \
	cd ${WRKDIR}/${PORTNAME}-sound-${PORTVERSION}/data; \
	${FIND} . -type d | cut -c2- | ${SED} \
	's|^|@dirrm ${DATADIR:S,${PREFIX}/,,}/data|' | ${SORT} -r >> ${PLIST};
	${ECHO_CMD} "@dirrm ${DATADIR:S,${PREFIX}/,,}" >> ${PLIST};
.endif

.if defined(WITH_SOUND)
post-install::
	cd ${WRKDIR}/${PORTNAME}-sound-${PORTVERSION}/data; \
	${RM} Make*; \
	${CP} -R ${WRKDIR}/${PORTNAME}-sound-${PORTVERSION}/data \
	${DATADIR};
.endif

.include <bsd.port.post.mk>
