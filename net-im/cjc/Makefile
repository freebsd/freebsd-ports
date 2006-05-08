# New ports collection makefile for:	cjc
# Date created:		19 April 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cjc
PORTVERSION=	1.0.0
CATEGORIES=	net-im python
MASTER_SITES=	http://jabberstudio.2nw.net/cjc/

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	The Console Jabber Client

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyxmpp>=1.0.0:${PORTSDIR}/net-im/py-pyxmpp

USE_PYTHON=	2.3+
MAKE_ENV+=	prefix=${PREFIX} pkg_datadir=${DATADIR} INSTALL_DIR="${INSTALL} -d"
MAKE_ARGS+=	-E prefix -E pkg_datadir -E pkg_docdir -E INSTALL -E INSTALL_DATA \
		-E INSTALL_DIR

.ifdef NOPORTDOCS
MAKE_ENV+=	pkg_docdir= DOCS=
MAKE_ARGS+=	-E DOCS
.else
MAKE_ENV+=	pkg_docdir=${DOCSDIR}
PORTDOCS=	manual.html COPYING ChangeLog README TODO
.endif

post-patch:
	@${GREP} -lr '/usr/bin/python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e "s!/usr/bin/python!${PYTHON_CMD}!"

.include <bsd.port.mk>
