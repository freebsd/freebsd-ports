# ex:ts=8
# Ports collection makefile for:	GraceTMPL
# Date created:			Oct 28, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gracetmpl
PORTVERSION=	0.3.1
PORTREVISION=	3
CATEGORIES=	math print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric.pth:${PORTSDIR}/math/py-numeric
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric.pth:${PORTSDIR}/math/py-numeric

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provide an easy way to use existing grace-files as a template

USE_REINPLACE=	yes
USE_GETOPT_LONG=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
ALL_TARGET=	all pythonwrap
INSTALL_TARGET=	install python_install

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500041
CFLAGS+=	"${CPPFLAGS}"
MAKE_ENV=	LDFLAGS="${LDFLAGS}"
.endif

post-extract:
	@${CP} -f ${WRKSRC}/Makefile.defs.tmpl ${WRKSRC}/Makefile.defs

post-patch:
	@${REINPLACE_CMD} -e "s|^PREFIX|#PREFIX|" ${WRKSRC}/Makefile.defs
	@${REINPLACE_CMD} -e "s@\(gracetmpl\.a\)@lib\1@g" \
		-e "s|make|${GMAKE}|" -e "s|install -D|install|" \
		-e "s|^CPPFLAGS =|CPPFALGS+=|" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|values\.h|float.h|" ${WRKSRC}/gracetmpl.cpp

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${CP} ${WRKSRC}/doc/html/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
