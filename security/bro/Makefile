# ex:ts=8
# Ports collection makefile for:  bro
# Date created:			  Sat Feb 28, 1998
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	bro
PORTVERSION=	0.5a
CATEGORIES=	security
#MASTER_SITES=	ftp://ee.lbl.gov/
#see http://www-nrg.ee.lbl.gov/bro-info.html
DISTNAME=	vp-bro-0.5-alpha

MAINTAINER=	obrien@FreeBSD.org

RESTRICTED=	"Author wishes Alpha releases not to be distrubted."

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/vp-bro-0.5-alpha${EXTRACT_SUFX})
IGNORE=is still in alpha test.  Please contact Vern Paxson <vern@ee.lbl.gov> to obtain the obtain the Bro source.  Put it in ${DISTDIR} as ${DISTFILES} and run make again
.endif

IS_INTERACTIVE=	"manual fetch"
WRKSRC=		${WRKDIR}/bro-pub-0.5a1
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
GNU_CONFIGURE=	yes

post-patch:
	@${MV} ${WRKSRC}/util.cc ${WRKSRC}/util.cc.in
	@${SED} -e "s|/usr/src/rtsg/bro/policy:/usr/local/lib/bro|${PREFIX}/share/bro|" \
		${WRKSRC}/util.cc.in >${WRKSRC}/util.cc
pre-install:
	@${MKDIR} ${PREFIX}/share/bro

post-install:
	@strip ${PREFIX}/sbin/bro
	@${INSTALL_DATA} ${WRKSRC}/policy/*.* ${PREFIX}/share/bro
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/bro
	${INSTALL_MAN} ${WRKSRC}/doc/bro-usenix98-revised.ps \
		${PREFIX}/share/doc/bro
	@${GZIP_CMD} ${PREFIX}/share/doc/bro/bro-usenix98-revised.ps
.endif

.include <bsd.port.post.mk>
