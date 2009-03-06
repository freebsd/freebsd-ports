# New ports collection makefile for:	vnstati
# Date created:		28 Dez 2008
# Whom:			Dennis Herrmann <adox@mcx2.org>
#
# $FreeBSD$
#

PORTNAME=	vnstati
DISTVERSION=	beta3
CATEGORIES=	net
MASTER_SITES=	http://humdi.net/vnstat/ \
		http://mirror.mcx2.org/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	PNG image output support for vnStat

LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
RUN_DEPENDS+=	vnstat:${PORTSDIR}/net/vnstat

ALL_TARGET=	vnstati
MAKE_ARGS=	LIBRARY_PATH="${PREFIX}/lib" \
		CPATH="${PREFIX}/include"

USE_GMAKE=	yes
MAN1=	vnstati.1
MANCOMPRESSED=	yes

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README
PORTEXAMPLES=	vnstat.cgi

post-patch:
	@${REINPLACE_CMD} -e 's|$$(DESTDIR)/usr/bin|$${PREFIX}/bin|g' \
		-e 's|$$(DESTDIR)/usr/share/man|$${PREFIX}/man|g' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/vnstat.cgi ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
