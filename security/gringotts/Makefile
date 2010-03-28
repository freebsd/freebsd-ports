# New ports collection makefile for:	gringotts
# Date created:				02 July 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gringotts
PORTVERSION=	1.2.10
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK application to securely store sensitive data

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		gringotts.2:${PORTSDIR}/security/libgringotts

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		'/^install-data-am:/s|install-DsktpDATA|| ; \
		 /^install-data-am:/s|install-docDATA|| ; \
		 s|@md5sum|@md5|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^install-exec-am:/s|install-exec-local||' ${WRKSRC}/src/Makefile.in

post-install:
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS BUGS ChangeLog FAQ NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
