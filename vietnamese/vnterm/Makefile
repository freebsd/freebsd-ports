# ex:ts=8
# Ports collection makefile for:    vnterm
# Date created:         Sat July 20, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	vnterm
PORTVERSION= 	3.3
CATEGORIES=	vietnamese x11
MASTER_SITES=	ftp://ftp.media.mit.edu/pub/Vietnet/Viscii/Unix/  \
		ftp://ftp.monash.edu.au/pub/vietnam/unix/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	obrien@FreeBSD.org

USE_IMAKE=	yes
XMKMF=		xmkmf
CFLAGS+=	-I../../include

post-patch:
	@${LN} ${WRKSRC}/XTerm.ad ${WRKSRC}/VNTerm.ad
	@${LN} ${WRKSRC}/vnterm.1V ${WRKSRC}/vnterm.man

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
		&& ${CHMOD} a+rx ${PREFIX}/share/doc/vnterm
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/vnterm
.endif

.include <bsd.port.mk>
