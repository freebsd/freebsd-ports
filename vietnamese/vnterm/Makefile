# ex:ts=8
# New ports collection makefile for:    vnterm
# Version required:     3.3
# Date created:         Sat July 20, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.1.1.1 1996/08/09 04:17:16 asami Exp $
#

DISTNAME=	vnterm3.3
PKGNAME=	vn-vnterm-3.3
CATEGORIES=	vietnamese x11
MASTER_SITES=	ftp://ftp.media.mit.edu/pub/Vietnet/Viscii/Unix/  \
		ftp://ftp.monash.edu.au/pub/vietnam/unix/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     obrien@cs.ucdavis.edu

USE_IMAKE=	yes
XMKMF=		xmkmf
CFLAGS+=	-I../../include

post-patch:
	@/bin/ln ${WRKSRC}/XTerm.ad ${WRKSRC}/VNTerm.ad
	@/bin/ln ${WRKSRC}/vnterm.1V ${WRKSRC}/vnterm.man

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/VNterm.sh ${PREFIX}/bin/VNterm 
	@${MKDIR} ${PREFIX}/lib/X11/fonts/vietnamese
	@(cd ${WRKSRC}/../fonts/X ; \
	${INSTALL_DATA} fonts.dir *.pcf.Z  \
		${PREFIX}/lib/X11/fonts/vietnamese ; \
	)
			/bin/false
			need to put below line in pkg/INSTALL?
	@(cd ${PREFIX}/lib/X11/fonts/vietnamese ; mkfontdir >/dev/null 2>&1)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/vnterm \
		&& chmod a+rx ${PREFIX}/share/doc/vnterm
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/vnterm
.endif

.include <bsd.port.mk>
