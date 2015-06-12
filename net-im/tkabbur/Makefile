# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	tkabbur
PORTVERSION=	0.8
CATEGORIES=	net-im
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Is a modification of XMPP/Jabber client Tkabber

RUN_DEPENDS=	dtplite:${PORTSDIR}/devel/tcllib \
		tcltls>0:${PORTSDIR}/devel/tcltls \
		${LOCALBASE}/lib/bwidget/pkgIndex.tcl:${PORTSDIR}/x11-toolkits/bwidget

DEPRECATED=	Upstream development ceased since 2008
EXPIRATION_DATE=	2015-07-07

WRKSRC=		${WRKDIR}/${DISTNAME}
USES=		tar:bzip2 tk:run
NO_BUILD=	yes

SUBDIRS=	contrib emoticons ifacetk jabberlib mclistbox \
		msgs pixmaps plugins sounds tclxml trans

do-install:
	${ECHO} -e "#!/bin/sh\nexec ${WISH} ${DATADIR}/tkabbur.tcl \
		-name tkabbur \"\$$@\"\n" > ${STAGEDIR}${PREFIX}/bin/tkabbur
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/tkabbur
	${CHMOD} 755 ${WRKSRC}/*.tcl
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} ${WRKSRC}/*.tcl ${STAGEDIR}${DATADIR}
.for i in ${SUBDIRS}
	${CHMOD} -R 755 ${WRKSRC}/${i}
	${CP} -R ${WRKSRC}/${i} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
