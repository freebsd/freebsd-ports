# New ports collection makefile for:	gentoo
# Date created:				12 August 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	gentoo
PORTVERSION=	0.11.16
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.obsession.se/gentoo/ \
		http://www.ibiblio.org/pub/linux/utils/file/managers/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	anders@fix.no

USE_GTK=	yes

MAN1=		gentoo.1

DOCS=		BUGS CONFIG-CHANGES CREDITS FIXES-0.11 FIXES-0.9 README \
		README.NLS README.gtkrc TODO gentoogtkrc-example

post-patch:
	@ ${MV} ${WRKSRC}/gentoorc-example ${WRKSRC}/gentoorc-example.Dist
	@ ${SED} 's#icons#${PREFIX}/share/gentoo/icons#' \
		${WRKSRC}/gentoorc-example.Dist > ${WRKSRC}/gentoorc-example

	@ ${MV} ${WRKSRC}/src/Makefile ${WRKSRC}/src/Makefile.patched
	@ ${SED} -e 's#/home/emil/data/projects/gentoo#${PREFIX}/share#' \
	-e 's#gtk-config#${GTK_CONFIG}#' ${WRKSRC}/src/Makefile.patched \
		> ${WRKSRC}/src/Makefile

	@ ${MV} ${WRKSRC}/widgets/Makefile ${WRKSRC}/widgets/Makefile.Dist
	@ ${SED} -e 's#gtk-config#${GTK_CONFIG}#' -e 's#^CC.*##' \
		${WRKSRC}/widgets/Makefile.Dist > ${WRKSRC}/widgets/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gentoo ${PREFIX}/bin
	@${INSTALL} -d -m 0755 ${PREFIX}/share/gentoo
	${CP} -R ${WRKSRC}/icons ${PREFIX}/share/gentoo
	${CHMOD} 0755 ${PREFIX}/share/gentoo/icons
	${INSTALL_DATA} ${WRKSRC}/gentoorc-example ${PREFIX}/etc/gentoorc
	${INSTALL_MAN} ${WRKSRC}/docs/gentoo.1x ${PREFIX}/man/man1/gentoo.1
.if !defined(NOPORTDOCS)
	${CP} -R ${WRKSRC}/docs ${PREFIX}/share/doc/gentoo
	${RM} ${PREFIX}/share/doc/gentoo/gentoo.1x
	${CHMOD} -R a+r,+X ${PREFIX}/share/doc/gentoo
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/gentoo
.endfor
.endif

.include <bsd.port.mk>
