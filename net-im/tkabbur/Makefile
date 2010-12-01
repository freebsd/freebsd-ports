# New ports collection makefile for:	tkabbur
# Date created:				06 October 2008
# Whom:					Dennis Herrmann <adox@mcx2.org>
#
# $FreeBSD$
#

PORTNAME=	tkabbur
PORTVERSION=	0.8
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Is a modification of XMPP/Jabber client Tkabber

RUN_DEPENDS=	dtplite:${PORTSDIR}/devel/tcllib \
		${LOCALBASE}/lib/tls/pkgIndex.tcl:${PORTSDIR}/devel/tcltls \
		${LOCALBASE}/lib/bwidget/pkgIndex.tcl:${PORTSDIR}/x11-toolkits/bwidget

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_BZIP2=	yes
NO_BUILD=	yes

USE_TK_RUN=	84+

SUBDIRS=	contrib emoticons ifacetk jabberlib mclistbox \
		msgs pixmaps plugins sounds tclxml trans

.include <bsd.port.pre.mk>

do-install:
	${ECHO} -e "#!/bin/sh\nexec ${WISH} ${DATADIR}/tkabbur.tcl \
		-name tkabbur \"\$$@\"\n" > ${PREFIX}/bin/tkabbur
	${CHMOD} +x ${PREFIX}/bin/tkabbur
	${CHMOD} 755 ${WRKSRC}/*.tcl
	${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/*.tcl ${DATADIR}
.for i in ${SUBDIRS}
	${CHMOD} -R 755 ${WRKSRC}/${i}
	${CP} -R ${WRKSRC}/${i} ${DATADIR}
.endfor

.include <bsd.port.post.mk>
