# New ports collection makefile for:	amsn
# Date created:		01 Feb 2003
# Whom:			Andreas Klemm <andreas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	amsn
PORTVERSION=	0.83
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/}

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	MSN Messenger

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		${LOCALBASE}/lib/tcllib1.3/base64/base64.tcl:${PORTSDIR}/devel/tcllib


NO_BUILD=	yes
WRKSRC=		${WRKDIR}/msn

BROKEN=		"Broken dependencies"

LIBDIR=		${PREFIX}/lib/msn
DOCSDIR=	${PREFIX}/share/doc/amsn
CORE=		FAQ HELP README amsn jwakeup langlist *tcl *htm*
SUBDIR=		icons lang skins
DOC_FILES=	README TODO

post-extract:
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -rf
	@${RM} -rf ${WRKSRC}/skins/default/smileys/.xvpics

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
	@sed -e "s=!!PREFIX!!=${PREFIX}=" < ${FILESDIR}/amsn \
		> ${PREFIX}/bin/amsn
	@${CHMOD} 555 ${PREFIX}/bin/amsn
	@${CHMOD} 555 ${PREFIX}/lib/msn/amsn
	@uudecode -o ${PREFIX}/lib/msn/icons/logolinmsn.gif \
		${FILESDIR}/logolinmsn.gif.uue

.include <bsd.port.mk>
