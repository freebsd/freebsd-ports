# New ports collection makefile for:	gentoo
# Date created:				12 August 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	gentoo
PORTVERSION=	0.11.34
PORTCOMMENT=	Gtk+ based, file manager inspired by DirectoryOpus
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	obraun@FreeBSD.org

USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

MAN1=		gentoo.1

PORTDOCS=	BUGS CONFIG-CHANGES CREDITS NEWS README README.NLS \
		README.gtkrc TODO

post-patch:
	@${REINPLACE_CMD} -e 's|icons|${DATADIR}/icons|g' ${WRKSRC}/gentoorc.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/gentoo.1x ${MANPREFIX}/man/man1/gentoo.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${TAR} -C ${WRKSRC}/docs --exclude "gentoo.1x" -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${FIND} ${DOCSDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DOCSDIR} | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${FIND} ${DOCSDIR} -type d | ${XARGS} ${CHMOD} a+x
.endif

.include <bsd.port.mk>
