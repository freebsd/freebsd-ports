# New ports collection makefile for:	gentoo
# Date created:				12 August 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	gentoo
PORTVERSION=	0.11.18
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_GTK=	yes
GNU_CONFIGURE=	yes

MAN1=		gentoo.1

PORTDOCS=	BUGS CONFIG-CHANGES CREDITS NEWS README README.NLS \
		README.gtkrc TODO

post-patch:
	@${PERL} -pi -e 's|icons|${DATADIR}/icons|g' ${WRKSRC}/gentoorc.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/gentoo.1x ${MANPREFIX}/man/man1/gentoo.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${TAR} -C ${WRKSRC}/docs --exclude "gentoo.1x" -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@find ${DOCSDIR} | xargs ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@find ${DOCSDIR} | xargs ${CHMOD} ${SHAREMODE}
	@find ${DOCSDIR} -type d | xargs ${CHMOD} a+x
.endif

.include <bsd.port.mk>
