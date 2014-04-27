# Created by: kamikaze@bsdforen.de
# $FreeBSD$

PORTNAME=	libbluray
PORTVERSION=	0.5.0
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/${PORTNAME}/${PORTVERSION}/ \
		http://blu.opsec.eu/

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Blu-Ray discs playback library for media players

LICENSE=	LGPL21

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2
# dlopen dependencies, libbdplus not yet available
LIB_DEPENDS+=	libaacs.so:${PORTSDIR}/multimedia/libaacs

USES=		iconv pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf aclocal automake libtool
USE_GNOME=	libxml2

HAS_CONFIGURE=	yes
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--disable-debug

OPTIONS_DEFINE=	JAVA
JAVA_DESC=	Enable Blu-Ray Java support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJAVA}
BUILD_DEPENDS+=	ant:${PORTSDIR}/devel/apache-ant
CATEGORIES+=	java
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_BUILD=	yes
JAVA_RUN=	yes
CONFIGURE_ARGS+=	--enable-bdjava --with-bdj-type=j2se
CONFIGURE_ENV+=	JDK_HOME="${JAVA_HOME}"
.endif

# Create PLIST_SUB definitions for options
.for _option in ${OPTIONS_DEFINE}
.if ${PORT_OPTIONS:M${_option}}
PLIST_SUB+=	${_option}=""
.else
PLIST_SUB+=	${_option}="@comment "
.endif
.endfor

run-autotools:
	@cd ${WRKSRC} && ${SH} bootstrap

plist:
	@${ECHO} "===> Rebuilding PLIST."
.for _option in "" ${OPTIONS_DEFINE}
	@${MAKE} clean stage OPTIONS_EXCLUDE="${OPTIONS_DEFINE:N${_option}}" \
	                     WITH=${_option}
	@${MTREE_CMD} -cp "${STAGEDIR}${PREFIX}/" > "${WRKDIR}/mtree.${_option}"
	@${MTREE_CMD} -Sf "${WRKDIR}/mtree.${_option}" -f "${MTREE_FILE}" \
		| ${SED} -ne '/share\/licenses/b dirs' \
		         -e '/ dir /{s/ .*//;s/^/@dirrm /;H;};t dirs' \
		         -e 's/ .*//p;:dirs' -e '$${g;s/^\n//p;}' \
		> "plist.${_option}"
.endfor
.for _option in ${OPTIONS_DEFINE}
	@${GREP} -vFx "$$(${CAT} "plist.")" "plist.${_option}" \
		| ${SED} 's/^/%%${_option}%%/' > "plist.add.${_option}"
	@${RM} "plist.${_option}"
.endfor
	@${CAT} plist. ${OPTIONS_DEFINE:C/^/plist.add./} > ${PLIST}
	@${RM} plist. ${OPTIONS_DEFINE:C/^/plist.add./}

.include <bsd.port.mk>
