# New ports collection makefile for:	pyrenamer
# Date created:				14 June 2007
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyrenamer
PORTVERSION=	0.1
CATEGORIES=	sysutils python gnome
MASTER_SITES=	http://www.infinicode.org/code/${PORTNAME}/

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A mass file renamer written in PyGTK

USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gconf2 pygtk2
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

DOCS=		AUTHORS COPYING ChangeLog NEWS README
MAN1=		pyrenamer.1
GCONF_SCHEMAS=	pyrenamer.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|[(]datadir[)]/doc|(prefix)/share/examples|g' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|[(]datadir[)]/applications|(prefix)/share/applications|g' \
		${WRKSRC}/data/Makefile.in

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
