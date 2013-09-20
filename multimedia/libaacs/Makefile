# Created by: kamikaze@bsdforen.de
# $FreeBSD$

PORTNAME=	libaacs
PORTVERSION=	0.6.0
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/${PORTNAME}/${PORTVERSION}/ \
		http://blu.opsec.eu/

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Advanced Access Content System implementation

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf aclocal automake libtool
USES=		bison gettext iconv

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	LEX="${LOCALBASE}/bin/flex"
CONFIGURE_ARGS+=	--prefix="${PREFIX}" \
		--disable-debug
# Evil hack, necessitating another evil hack in the plist target.
MAKE_ARGS+=	pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		CFLAGS=${CFLAGS:Q}

NO_STAGE=	yes
run-autotools:
	@cd ${WRKSRC} && ${SH} bootstrap

plist: build
	@${ECHO} "===> Rebuilding PLIST."
	@${MKDIR} "${WRKDIR}/plist"
	@cd ${WRKSRC} && ( \
		${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS} --prefix="${WRKDIR}/plist" && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} pkgconfigdir="${WRKDIR}/plist/libdata/pkgconfig" ${INSTALL_TARGET} ; \
		${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS} \
	)
	@${FIND} -ds "${WRKDIR}/plist/" -not -type d \
		| ${SED} "s|${WRKDIR}/plist/||1" > ${PLIST}
	@${FIND} -ds "${WRKDIR}/plist/" -type d -mindepth 2 \
		| ${SED} -e "/pkgconfig/d" -e "s|${WRKDIR}/plist/|@dirrm |1" >> ${PLIST}
	@${RM} -rf "${WRKDIR}/plist"

.include <bsd.port.mk>
