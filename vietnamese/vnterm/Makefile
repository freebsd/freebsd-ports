# ex:ts=8
# New ports collection makefile for:    vnterm
# Version required:     3.3
# Date created:         Sat July 20, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.9 1997/10/13 07:12:28 obrien Exp $
#

DISTNAME=	vnterm3.3
PKGNAME=	vi-vnterm-3.3
CATEGORIES=	vietnamese x11
MASTER_SITES=	ftp://ftp.media.mit.edu/pub/Vietnet/Viscii/Unix/  \
		ftp://ftp.monash.edu.au/pub/vietnam/unix/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     obrien@FreeBSD.org

BROKEN_ELF=	yes

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
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/vnterm \
		&& chmod a+rx ${PREFIX}/share/doc/vnterm
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/vnterm
.endif

.include <bsd.port.mk>
