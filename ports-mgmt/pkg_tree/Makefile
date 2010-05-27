# New ports collection makefile for:   pkg_tree
# Date created:        24 September 2001
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	pkg_tree
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Get a 'graphical' tree-overview of installed packages

USE_PERL5=	yes

MAN7=		pkg_tree.7
PLIST_FILES=	bin/pkg_tree

post-patch:
	@${REINPLACE_CMD} -e 's|__PREFIX__|${PREFIX}|g ; \
		s|__INSTALL_MAN__|${INSTALL_MAN}|g ; \
		s|__INSTALL_SCRIPT__|${INSTALL_SCRIPT}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|#!/usr/bin/perl -w|#!${PERL5} -w|' \
		${WRKSRC}/pkg_tree

.include <bsd.port.mk>
