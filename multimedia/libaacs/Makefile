# Created by: kamikaze@bsdforen.de
# $FreeBSD$

PORTNAME=	libaacs
PORTVERSION=	0.7.0
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/${PORTNAME}/${PORTVERSION}/ \
		http://blu.opsec.eu/

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Advanced Access Content System implementation

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf aclocal automake libtool
USES=		bison gettext iconv tar:bzip2

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	LEX="${LOCALBASE}/bin/flex"
CONFIGURE_ARGS+=	--prefix="${PREFIX}" \
		--disable-debug
# Evil hack, necessitating another evil hack in the plist target.
MAKE_ARGS+=	pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		CFLAGS=${CFLAGS:Q}

run-autotools:
	@cd ${WRKSRC} && ${SH} bootstrap

plist: stage
	@${ECHO} "===> Rebuilding PLIST."
	@${MTREE_CMD} -cp "${STAGEDIR}${PREFIX}/" > "${WRKDIR}/plist.mtree"
	@${MTREE_CMD} -Sf "${WRKDIR}/plist.mtree" -f "${MTREE_FILE}" \
		| ${SED} -ne '/ dir /{s/ .*//;s/^/@dirrm /;H;};t dirs' \
		         -e 's/ .*//p;:dirs' -e '$${g;s/^\n//p;}' > ${PLIST}

.include <bsd.port.mk>
