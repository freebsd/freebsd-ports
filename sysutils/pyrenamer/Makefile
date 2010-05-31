# New ports collection makefile for:	pyrenamer
# Date created:				14 June 2007
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/pyrenamer/Makefile,v 1.1 2007/08/14 21:33:09 mezz Exp $
#

PORTNAME=	pyrenamer
PORTVERSION=	0.6.0
PORTREVISION=	4
CATEGORIES=	sysutils python gnome
MASTER_SITES=	http://www.infinicode.org/code/pyrenamer/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mass file renamer written in PyGTK

USE_GNOME=	gconf2 gnomehack pygtk2
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		pyrenamer.1
GCONF_SCHEMAS=	pyrenamer.schemas

.if defined(WITHOUT_HACHOIR)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/eyeD3/__init__.py:${PORTSDIR}/audio/py-eyed3
.else
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/hachoir_metadata/__init__.py:${PORTSDIR}/sysutils/hachoir-metadata
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/pyrenamer.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for file in treefilebrowser_example.py
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
