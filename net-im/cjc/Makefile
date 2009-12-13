# New ports collection makefile for:	cjc
# Date created:		19 April 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cjc
PORTVERSION=	1.0.0.675
CATEGORIES=	net-im python
MASTER_SITES=	CENKES http://jabberstudio.2nw.net/cjc/
# svn export -r675 http://cjc.jajcus.net/svn/cjc/trunk cjc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Console Jabber Client

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyxmpp>=1.0.0.644:${PORTSDIR}/net-im/py-pyxmpp

USE_BZIP2=	yes
USE_PYTHON=	2.4+
MAKE_ENV+=	prefix=${PREFIX} pkg_datadir=${DATADIR} INSTALL_DIR="${INSTALL} -d"
MAKE_ARGS+=	-E prefix -E pkg_datadir -E pkg_docdir -E INSTALL -E INSTALL_DATA \
		-E INSTALL_DIR

.ifndef NOPORTDOCS
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt \
		docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
MAKE_ENV+=	pkg_docdir=${DOCSDIR}
PORTDOCS=	manual.html COPYING README TODO
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/.svn

post-patch:
.ifdef NOPORTDOCS
	@${REINPLACE_CMD} -e '/^DOCS=/s|=.*|=|' -e '/$$(DESTDIR)$$(pkg_docdir)/d' ${WRKSRC}/Makefile
.endif
	@${GREP} -lr '/usr/bin/python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e "s!/usr/bin/python!${PYTHON_CMD}!"
	@${REINPLACE_CMD} -e '/^XSLTPROC=/s|=.*|=${LOCALBASE}/bin/xsltproc|' \
			-e '/^XSL_DIR=/s|=.*|=${LOCALBASE}/share/xsl/docbook/|' ${WRKSRC}/doc/Makefile
	@${REINPLACE_CMD} -e '/^DOCS=/s|ChangeLog||' ${WRKSRC}/Makefile

.include <bsd.port.mk>
