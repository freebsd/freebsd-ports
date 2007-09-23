# New ports collection makefile for:    send
# Date created:         19.09.2007
# Whom: Janos Mohacsi <mohacsi@niif.hu>
#
# $FreeBSD$

PORTNAME=	send
PORTVERSION=	0.2
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	#http://www.docomolabs-usa.com/lab_osrc_guide.html
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Secure Neighbor Discovery implementation for IPv6

LIB_DEPENDS=	dnet.1:${PORTSDIR}/net/libdnet

RESTRICTED=	not redistributable, license agreement required

USE_ZIP=	yes
USE_GMAKE=	yes
SUB_FILES=	pkg-message

PORTDOCS=	UserGuide.pdf

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 600000
BROKEN=		doesn't compile in FreeBSD > 6.0
.endif

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		needs you to sign the agreement on "http://www.docomolabs-usa.com/lab_osrc_downl.html", download it manually, place in ${DISTDIR} and then restart this build
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" -e "s|%%LOCALBASE%%|${LOCALBASE}|" \
		${WRKSRC}/Makefile.config \
		${WRKSRC}/sendd/sendd_local.h \
		${WRKSRC}/sendd/os-freebsd/Makefile \
		${WRKSRC}/sendd/os-freebsd/sendd \
		${WRKSRC}/examples/sendd.conf \
		${WRKSRC}/examples/params.conf \
		${WRKSRC}/examples/ipext/ipext_verify.conf

post-install:
	${MKDIR} ${PREFIX}/etc/sendd/
	${INSTALL_DATA} ${WRKSRC}/examples/sendd.conf ${PREFIX}/etc/sendd/sendd.conf-dist
	${INSTALL_DATA} ${WRKSRC}/examples/params.conf ${PREFIX}/etc/sendd/params.conf-dist
	${INSTALL_DATA} ${WRKSRC}/examples/ipext/ipext_verify.conf ${PREFIX}/etc/sendd/ipext.conf-dist
	@${CAT} ${PKGMESSAGE}
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${doc} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>
