# New ports collection makefile for:   pkg_tree
# Date created:        24 September 2001
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	pkg_tree
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org

USE_REINPLACE=	yes
USE_PERL5=	yes

MAN7=		pkg_tree.7

post-patch:
	@${REINPLACE_CMD} -e 's|__PREFIX__|${PREFIX}|g ; \
		s|__INSTALL_MAN__|${INSTALL_MAN}|g ; \
		s|__INSTALL_SCRIPT__|${INSTALL_SCRIPT}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
