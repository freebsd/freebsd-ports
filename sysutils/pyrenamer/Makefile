# New ports collection makefile for:	pyrenamer
# Date created:				14 June 2007
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/pyrenamer/Makefile,v 1.1 2007/08/14 21:33:09 mezz Exp $
#

PORTNAME=	pyrenamer
DISTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	sysutils python gnome
MASTER_SITES=	http://www.infinicode.org/code/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mass file renamer written in PyGTK

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/eyeD3/__init__.py:${PORTSDIR}/audio/py-eyed3
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/eyeD3/__init__.py:${PORTSDIR}/audio/py-eyed3

USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gconf2 pygtk2
USE_PYTHON=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCS=		AUTHORS COPYING ChangeLog NEWS README
MAN1=		pyrenamer.1
GCONF_SCHEMAS=	pyrenamer.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|[$$][(]datadir[)]/doc/pyrenamer|${EXAMPLESDIR}|g' \
		${WRKSRC}/doc/Makefile.in

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
