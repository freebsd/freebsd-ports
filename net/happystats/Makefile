# New ports collection makefile for:	happystats
# Date created:		2004-01-12
# Whom:	      		Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	happystats
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.happystats.org/srcs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kiwi@oav.net
COMMENT=	Universal log converter into graph

BUILD_DEPENDS=	imake:${X_IMAKE_PORT}
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		rrd.0:${PORTSDIR}/net/rrdtool

USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes

MAN1=		happystats.1
MANCOMPRESSED=	yes
DOCS=		AUTHORS INSTALL TODO

.include <bsd.port.pre.mk>

do-configure:
	@cd ${WRKSRC} && ${MAKE} dep

post-configure:
.if ${OSVERSION} > 500041
	@${REINPLACE_CMD} -E -e 's|-lgnugetopt||g' ${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/happystats ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/happystats.1.gz ${MAN1PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/www/cgi-bin
	${INSTALL_PROGRAM} ${WRKSRC}/happystats.cgi ${PREFIX}/www/cgi-bin
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
