# New ports collection makefile for:	amsn
# Date created:		01 Feb 2003
# Whom:			Andreas Klemm <andreas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	amsn
PORTVERSION=	0.92
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/}

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	MSN Messenger

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib
BUILD_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		convert:${PORTSDIR}/graphics/ImageMagick \
		${LOCALBASE}/lib/tls/tls.tcl:${PORTSDIR}/devel/tcltls \
		${LOCALBASE}/lib/tcllib1.6/base64/base64.tcl:${PORTSDIR}/devel/tcllib
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/msn

LIBDIR=		${PREFIX}/lib/msn
DOCSDIR=	${PREFIX}/share/doc/amsn
CORE=		FAQ HELP README amsn jwakeup langlist amsn-remote remote.help \
		*tcl *htm*
SUBDIR=		icons lang skins plugins
DOC_FILES=	README TODO

post-extract:
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -rf
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${RM} -rf
	@${FIND} ${WRKSRC} -name .xvpics | ${XARGS} ${RM} -rf

do-configure:
	export WISH=`which wish8.4` && ${SED} s=!!PREFIX!!=`dirname $${WISH}|${SED} sx/binxxg`=g ${FILESDIR}/Makefile.traydoc | ${SED} s=!!X11BASE!!=${X11BASE}=g > ${WRKSRC}/plugins/traydock/Makefile

do-build:
	cd ${WRKSRC}/plugins/traydock && make && ${RM} Makefile

do-install:
	@${MKDIR} ${LIBDIR}
	@cd ${WRKSRC}; tar cf - ${CORE} | ( cd ${LIBDIR}; tar xpf - )
.for i in ${SUBDIR}
	@cd ${WRKSRC}; tar cf - ${i} | ( cd ${LIBDIR}; tar xpf - )
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOC_FILES}
	@${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${SED} -e "s=!!PREFIX!!=${PREFIX}=" < ${FILESDIR}/amsn \
		> ${PREFIX}/bin/amsn
	@${CHMOD} 555 ${PREFIX}/bin/amsn
	@${CHMOD} 555 ${PREFIX}/lib/msn/amsn
	@uudecode -o ${PREFIX}/lib/msn/skins/default/pixmaps/logolinmsn.gif \
		${FILESDIR}/logolinmsn.gif.uue

.include <bsd.port.mk>
