# Created by: kamikaze@bsdforen.de
# $FreeBSD$

PORTNAME=	libbluray
PORTVERSION=	0.7.0
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/${PORTNAME}/${PORTVERSION}/ \
		http://blu.opsec.eu/

MAINTAINER=	kami@FreeBSD.org
COMMENT=	Blu-Ray discs playback library for media players

LICENSE=	LGPL21

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig
# dlopen dependencies
LIB_DEPENDS+=	libaacs.so:${PORTSDIR}/multimedia/libaacs \
		libbdplus.so:${PORTSDIR}/multimedia/libbdplus

INSTALL_TARGET=	install-strip
USES=		autoreconf iconv libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes

.include "Makefile.include"

OPTIONS_DEFINE=	JAVA
OPTIONS_SUB=	yes
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

#
# NOTE:
# makeplist has no support for options, leave this in place
#

# Create PLIST_SUB definitions for options
.for _option in ${OPTIONS_DEFINE}
.if ${PORT_OPTIONS:M${_option}}
PLIST_SUB+=	${_option}=""
.else
PLIST_SUB+=	${_option}="@comment "
.endif
.endfor

plist:
	@${ECHO} "===> Rebuilding PLIST."
.for _option in "" ${OPTIONS_DEFINE}
	@${MAKE} clean stage OPTIONS_EXCLUDE="${OPTIONS_DEFINE:N${_option}}" \
	                     WITH=${_option}
	@${MTREE_CMD} -cp "${STAGEDIR}${PREFIX}/" > "${WRKDIR}/mtree.${_option}"
	@${MTREE_CMD} -Sf "${WRKDIR}/mtree.${_option}" -f "${MTREE_FILE}" \
		| ${SED} -e '/share\/licenses/d' -e '/ dir /d' -e 's/ .*//' \
		> "plist.${_option}"
.endfor
.for _option in ${OPTIONS_DEFINE}
	@${GREP} -vFx "$$(${CAT} "plist.")" "plist.${_option}" \
		| ${SED} 's/^/%%${_option}%%/' > "plist.add.${_option}"
	@${RM} "plist.${_option}"
.endfor
	@${CAT} plist. ${OPTIONS_DEFINE:C/^/plist.add./} \
		| ${SED} "${PLIST_SUB_SED}" > ${PLIST}
	@${RM} plist. ${OPTIONS_DEFINE:C/^/plist.add./}

.include <bsd.port.mk>
